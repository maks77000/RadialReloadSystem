class RadialReloadMenu : UIScriptedMenu
{
	static ref RadialReloadMenu instance;

	ref array<Magazine> magazines;
	ref array<RadialSegmentController> segments;

	static void Open()
	{
		if (!instance)
			instance = new RadialReloadMenu();

		GetGame().GetUIManager().ShowScriptedMenu(instance,NULL);
	}

	override Widget Init()
	{
		layoutRoot = GetGame().GetWorkspace().CreateWidgets("RadialReloadV4/gui/radial.layout");

		PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());

		RadialMagazineScanner.GetMagazines(player,magazines);

		segments = new array<RadialSegmentController>;

		for (int i = 0; i < magazines.Count() && i < 8; i++)
		{
			RadialSegmentController seg = new RadialSegmentController(layoutRoot,i,magazines[i]);
			segments.Insert(seg);
		}

		return layoutRoot;
	}

	override void Update(float timeslice)
	{
		super.Update(timeslice);

		int seg = RadialMouseDetector.GetSegment();

		for (int i = 0; i < segments.Count(); i++)
			segments[i].SetHighlight(i == seg);
	}

	override bool OnMouseButtonUp(Widget w,int x,int y,int button)
	{
		int seg = RadialMouseDetector.GetSegment();

		if (seg < magazines.Count())
		{
			PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());

			RadialReloadManager.Reload(player,magazines[seg]);
		}

		Close();
		return true;
	}
}
