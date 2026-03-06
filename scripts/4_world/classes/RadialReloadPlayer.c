class RadialReloadPlayer {
    static void Reload(PlayerBase player, string ammoType) {
        EntityAI item = player.GetItemInHands();
        if (!item) return;
        array<EntityAI> inventory = new array<EntityAI>;
        player.GetInventory().EnumerateInventory(InventoryTraversalType.PREORDER, inventory);
        foreach (EntityAI e : inventory) {
            if (e.GetType() == ammoType) {
                if(item.IsInherited(Magazine)) {
                    Magazine mag = Magazine.Cast(item);
                    int add = Math.Min(e.GetAmmoCount(), mag.GetAmmoMax() - mag.GetAmmoCount());
                    if(add > 0) {
                        mag.ServerAddAmmo(add);
                    }
                    return;
                }
                if(item.IsInherited(Weapon_Base)) {
                    Weapon_Base weapon = Weapon_Base.Cast(item);
                    weapon.ServerLoadMagazine(e);
                    return;
                }
            }
        }
    }
}