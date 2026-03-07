class RadialReloadPlayer {
    static void Reload(PlayerBase player, string ammoType) {
        if (!player || !ammoType || ammoType == "") return;

        EntityAI item = player.GetItemInHands();
        if (!item) return;

        array<EntityAI> inventory = new array<EntityAI>;
        player.GetInventory().EnumerateInventory(InventoryTraversalType.PREORDER, inventory);

        if (item.IsInherited(Magazine)) {
            Magazine heldMag = Magazine.Cast(item);
            foreach (EntityAI e : inventory) {
                if (e.GetType() != ammoType) continue;

                Ammunition_Base ammoEntity = Ammunition_Base.Cast(e);
                if (!ammoEntity) continue;

                int add = Math.Min(ammoEntity.GetAmmoCount(), heldMag.GetAmmoMax() - heldMag.GetAmmoCount());
                if (add <= 0) continue;

                heldMag.SetAmmoCount(heldMag.GetAmmoCount() + add);
                ammoEntity.SetAmmoCount(ammoEntity.GetAmmoCount() - add);
                return;
            }
            return;
        }

        if (item.IsInherited(Weapon_Base)) {
            Weapon_Base weapon = Weapon_Base.Cast(item);
            foreach (EntityAI e2 : inventory) {
                if (!e2.IsInherited(Magazine)) continue;

                Magazine candidateMag = Magazine.Cast(e2);
                if (!candidateMag) continue;
                if (candidateMag.GetAmmoTypeName(0) != ammoType) continue;

                weapon.ServerLoadMagazine(candidateMag);
                return;
            }
        }
    }
}
