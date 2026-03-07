class RadialSegmentController
{
	Widget root;
	ImageWidget icon;
	TextWidget ammoText;

	Magazine mag;

	void RadialSegmentController(Widget parent, int index, Magazine m)
	{
		mag = m;

		string name = "Segment" + index.ToString();
		root = parent.FindAnyWidget(name);

		if (!root)
			return;

		Widget segLayout = GetGame().GetWorkspace().CreateWidgets("RadialReloadV4/gui/layouts/radial_segment.layout", root);
		if (!segLayout)
			return;

		icon = ImageWidget.Cast(segLayout.FindAnyWidget("Icon"));
		ammoText = TextWidget.Cast(segLayout.FindAnyWidget("AmmoCount"));

		if (icon)
			icon.LoadImageFile(0, "set:dayz_inventory image:" + mag.GetType());

		if (ammoText)
			ammoText.SetText(mag.GetAmmoCount().ToString());
	}

	void SetHighlight(bool state)
	{
		if (!root)
			return;

		if (state)
			root.SetColor(0xAAFFFFFF);
		else
			root.SetColor(0x66000000);
	}
}