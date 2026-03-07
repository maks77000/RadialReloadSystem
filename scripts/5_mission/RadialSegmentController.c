class RadialSegmentController
{
	Widget root;
	ImageWidget icon;
	TextWidget ammoText;

	Magazine mag;

	void RadialSegmentController(Widget parent,int index,Magazine m)
{
	mag = m;

	string name = "Segment" + index;

	root = parent.FindAnyWidget(name);

	Widget segLayout = GetGame().GetWorkspace().CreateWidgets("RadialReloadV4/gui/radial_segment.layout",root);

	icon = ImageWidget.Cast(segLayout.FindAnyWidget("Icon"));
	ammoText = TextWidget.Cast(segLayout.FindAnyWidget("AmmoCount"));

	icon.LoadImageFile(0,"set:dayz_inventory image:" + mag.GetType());

	ammoText.SetText(mag.GetAmmoCount().ToString());
}

	void SetHighlight(bool state)
	{
		if (state)
			root.SetColor(0xAAFFFFFF);
		else
			root.SetColor(0x66000000);
	}
}
