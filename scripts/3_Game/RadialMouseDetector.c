class RadialMouseDetector
{
	static int GetSegment()
	{
		float x;
		float y;

		GetGame().GetWorkspace().GetMousePos(x,y);

		float cx = GetGame().GetScreenWidth() * 0.5;
		float cy = GetGame().GetScreenHeight() * 0.5;

		float dx = x - cx;
		float dy = y - cy;

		float angle = Math.Atan2(dy,dx);
		float deg = Math.Rad2Deg(angle);

		if (deg < 0)
			deg += 360;

		return Math.Floor(deg / 45);
	}
}