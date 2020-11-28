#version 330 core
vec3 white      = vec3(1.0, 1.0, 1.0);
vec3 black      = vec3(0.0, 0.0, 0.0);
vec3 red        = vec3(1.0, 0.0, 0.0);
vec3 green      = vec3(0.0, 1.0, 0.0);
vec3 blue       = vec3(0.0, 0.0, 1.0);
vec3 cyan       = vec3(0.0, 1.0, 1.0);
vec3 magenta    = vec3(1.0, 0.0, 1.0);
vec3 yellow     = vec3(1.0, 1.0, 0.0);
uniform vec2 mousePosition;
out vec4 frag_color;

void main() {
    frag_color      = vec4(white, 1.0);
    vec2 center     = mousePosition.xy;
    center.y        = 720 - center.y;
    vec2 Position   = gl_FragCoord.xy;
    float xR        = 200;                      //radius for X
    float yR        = 108;                      //radius for y

    float x1 = pow(( (Position.x - center.x) * cos(70) - (Position.y - center.y) * sin (70)), 2) / pow(xR, 2);
    float y1 = pow(( (Position.x - center.x) * sin(70) + (Position.y - center.y) * cos (70)), 2) / pow(yR, 2);
    float x2 = pow(( (Position.x - center.x) * cos(-70) - (Position.y - center.y) * sin (-70)), 2) / pow(xR, 2);
    float y2 = pow(( (Position.x - center.x) * sin(-70) + (Position.y - center.y) * cos (-70)), 2) / pow(yR, 2);
    bool InEllipse1 = (x1 + y1 <= 1);
    bool InEllipse2 = (x2 + y2 <= 1);
    if (InEllipse1 || InEllipse2)
    {
        frag_color = vec4(black, 1.0);
        if (Position.y < center.y)
        {
            if ( (InEllipse1 && !InEllipse2) || (InEllipse2 && !InEllipse1))
            {
                frag_color = vec4(white, 1.0);
            }
        }
    }
}