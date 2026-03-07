class RadialMouseDetector
{
	static int GetSegment()
	{
		int mouseX;
		int mouseY;
		int screenW;
		int screenH;

		GetGame().GetWorkspace().GetMousePos(mouseX, mouseY);
		GetGame().GetWorkspace().GetScreenSize(screenW, screenH);

		float x = mouseX;
		float y = mouseY;
		float cx = screenW * 0.5;
		float cy = screenH * 0.5;

		float dx = x - cx;
		float dy = y - cy;

		float angle = Math.Atan2(dy, dx);
		float deg = Math.Rad2Deg(angle);

		if (deg < 0)
			deg += 360;

		return Math.Floor(deg / 45);
	}
}