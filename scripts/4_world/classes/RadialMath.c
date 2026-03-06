class RadialMath {
    static float NormalizeAngle(float angle) {
        while (angle < 0) angle += 360;
        while (angle >= 360) angle -= 360;
        return angle;
    }

    static float GetMouseAngle(float mx, float my) {
        float a = Math.Atan2(my, mx) * Math.RAD2DEG;
        return NormalizeAngle(a);
    }
}