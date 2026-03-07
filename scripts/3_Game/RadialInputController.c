modded class MissionGameplay
{
	override void OnUpdate(float timeslice)
	{
		super.OnUpdate(timeslice);

		if (GetGame().GetInput().LocalPress("UAReloadRadial", false))
		{
			RadialReloadMenu.Open();
		}
	}
}