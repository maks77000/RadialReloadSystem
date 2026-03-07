class RadialReloadMenu : UIScriptedMenu {
    Widget root;
    ref array<ref RadialSegment> segments;
    float mx;
    float my;

    override Widget Init() {
        root = GetGame().GetWorkspace().CreateWidgets("RadialReloadAAA/gui/layouts/radial_reload.layout");

        segments = new array<ref RadialSegment>();
        BuildSegments();

        GetGame().GetInput().ChangeGameFocus(1);
        return root;
    }

    void BuildSegments() {
        array<string> ammoTypes = {
            "Ammo_9x19",
            "Ammo_545x39",
            "Ammo_556x45",
            "Ammo_762x39",
            "Ammo_12gaPellets",
            "Ammo_308Win"
        };

        float step = 360.0 / ammoTypes.Count();
        for (int i = 0; i < ammoTypes.Count(); i++) {
            float start = i * step;
            float end = start + step;
            if (end >= 360) end = 360;
            segments.Insert(new RadialSegment(ammoTypes[i], start, end));
        }
    }

    override void Update(float timeslice) {
        super.Update(timeslice);

        float x;
        float y;
        GetGame().GetMousePos(x, y);

        float cx = GetGame().GetScreenWidth() / 2;
        float cy = GetGame().GetScreenHeight() / 2;
        mx = x - cx;
        my = y - cy;
    }

    override bool OnMouseButtonUp(Widget w, int x, int y, int button) {
        float angle = RadialMath.GetMouseAngle(mx, my);

        foreach (RadialSegment s : segments) {
            if (!s.Contains(angle)) continue;
            SendReloadRPC(s.ammoType);
            break;
        }

        Close();
        return true;
    }

    void SendReloadRPC(string ammoType) {
        PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());
        if (!player) return;

        ScriptRPC rpc = new ScriptRPC();
        rpc.Write(ammoType);
        rpc.Send(player, 9001, true, null);
    }

    override void Close() {
        GetGame().GetInput().ChangeGameFocus(0);
        super.Close();
    }
}
