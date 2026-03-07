class RadialReloadManager
{
	static void Reload(PlayerBase player, Magazine mag)
	{
		if (!player || !mag)
			return;

		player.PredictiveTakeEntityToHands(mag);
	}
}
