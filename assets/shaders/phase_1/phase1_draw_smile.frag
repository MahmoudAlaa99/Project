#version 330 core
// The first line of any shader must a '#version" command which defines the glsl version to use

// This will be the output (you can choose any name) and it will be sent to the frame buffer (back buffer of the window).
out vec4 frag_color;
uniform vec2 mousePosition;

// This is entry point of the fragment shader and it will be called for every fragment covered by the rasterized geometry
void main() {
    // Here we just output a constant color which is red (R=1, G=0, B=0, A=1)
    
   float radius = 200;
   float radius2 = 25;
   float radius3 = 100;
   float radius4 = 80;
   vec2 position = gl_FragCoord.xy;
   position.y = 720 - position.y;
   vec2 offsetMain = vec2(mousePosition.x,mousePosition.y);
   vec2 offsetEye1 = vec2(mousePosition.x + 70,mousePosition.y - 50);
   vec2 offsetEye2 = vec2(mousePosition.x - 70,mousePosition.y - 50);
   vec2 offsetMouth = vec2(mousePosition.x,mousePosition.y + 30);

   
   float distMainCircle = distance(position,offsetMain);
   float distSmallCircle1 = distance(position,offsetEye1);
   float distSmallCircle2 = distance(position,offsetEye2);
   float distMouth = distance(position,offsetMouth);
    if(distMainCircle < radius){
    frag_color = vec4(0.0, 0.0, 0.0, 1.0);
    }
    if(distSmallCircle1 < radius2 || distSmallCircle2 < radius2) {
    frag_color = vec4(1.0,1.0,1.0,1.0);
    }
    if(distMouth < radius3 && distMouth > radius4 && position.y > offsetMouth.y) {
    frag_color = vec4(1.0,1.0,1.0,1.0);
    }
    if(distMainCircle > radius){
    frag_color = vec4(1.0, 1.0, 1.0, 1.0);
    }

}
