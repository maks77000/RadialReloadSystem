class RadialSegment { 
    float startAngle; 
    float endAngle; 
    string ammoType; 
    void RadialSegment(string type, float start, float end) { 
        ammoType = type; 
        startAngle = start; 
        endAngle = end; 
    } 
    bool Contains(float angle) { 
        if (startAngle <= endAngle) { 
            return angle >= startAngle && angle < endAngle; 
        } else { 
            return angle >= startAngle || angle < endAngle; 
        } 
    } 
}