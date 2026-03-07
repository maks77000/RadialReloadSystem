class RadialMagazineScanner
{
	static void GetMagazines(PlayerBase player, out array<Magazine> mags)
	{
		mags = new array<Magazine>;

		array<EntityAI> items = new array<EntityAI>;
		player.GetInventory().EnumerateInventory(InventoryTraversalType.PREORDER, items);

		foreach (EntityAI item : items)
		{
			Magazine mag;

			if (Class.CastTo(mag, item))
			{
				mags.Insert(mag);
			}
		}

		mags.Sort(SortMagazines);
	}

	static int SortMagazines(Magazine a, Magazine b)
	{
		return b.GetAmmoCount() - a.GetAmmoCount();
	}
}