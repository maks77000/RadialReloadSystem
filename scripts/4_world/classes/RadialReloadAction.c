class ActionOpenReloadRadial : ActionInteractBase {
    override string GetText() {
        return "Ammo Wheel";
    }
    override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item) {
        if (!item) return false;
        if (item.IsInherited(Weapon_Base) || item.IsInherited(Magazine)) return true;
        return false;
    }
    override void OnExecuteClient(ActionData action_data) {
        RadialReloadMenu menu = new RadialReloadMenu();
        GetGame().GetUIManager().ShowScriptedMenu(menu, null);
    }
}