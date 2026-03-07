static const int RADIAL_RELOAD_RPC = 9001;

modded class MissionGameplay {
    override void OnRPC(PlayerIdentity sender, Object target, int rpc_type, ParamsReadContext ctx) {
        super.OnRPC(sender, target, rpc_type, ctx);

        if (rpc_type != RADIAL_RELOAD_RPC) return;
        if (!GetGame().IsServer()) return;

        string ammoType;
        if (!ctx.Read(ammoType)) return;

        PlayerBase player = null;
        if (target && target.IsInherited(PlayerBase)) {
            player = PlayerBase.Cast(target);
        } else if (sender) {
            player = PlayerBase.Cast(GetGame().GetPlayerByIdentity(sender));
        }

        if (!player) return;

        RadialReloadPlayer.Reload(player, ammoType);
    }
}
