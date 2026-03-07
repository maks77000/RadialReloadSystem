modded class MissionGameplay {
    override void OnRPC(PlayerIdentity sender, Object target, int rpc_type, ParamsReadContext ctx) {
        super.OnRPC(sender, target, rpc_type, ctx);
        if (rpc_type == 9001) {
            string ammoType;
            if (!ctx.Read(ammoType)) return;
            PlayerBase player;
            if (target && target.IsInherited(PlayerBase)) player = PlayerBase.Cast(target);
            else player = PlayerBase.Cast(GetGame().GetPlayer());
            if (!player) return;
            RadialReloadPlayer.Reload(player, ammoType);
        }
    }
}