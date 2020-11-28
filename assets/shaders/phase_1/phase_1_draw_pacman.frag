#version 330 core

// Here we will define Uniform Variable
// they are called uniform because every run of the shader (under the same draw call) will see the same value
// so it is uniform across all executions of the shader
uniform vec3 color;
uniform vec2 mousePosition;


out vec4 frag_color;


void main(){
  vec2 position = gl_FragCoord.xy;
  position.y = 720 - position.y;

  vec2 x = mousePosition.xy;
  float circle = distance(position,x);
  vec2 offset  = vec2(x.x,x.y-120);
  float circle2 = distance(position,offset);
  vec2 pacmanUp = vec2(x.x +141.421 , x.y +141.421);
  vec2 pacmandown = vec2(x.x +141.421 , x.y -141.421);
  bool x1 = ((position.y - pacmanUp.y) < (position.x - pacmanUp.x)  );
  bool x2 = (abs(position.y - pacmandown.y) > abs(position.x - pacmandown.x));
  if(circle <= 200)
  {
    frag_color = vec4(0.0,0.0,0.0,1.0);
    if(circle2 < 20)
      frag_color = vec4(1.0,1.0,1.0,1.0);
    if( x1 && x2)
      frag_color = vec4(1.0,1.0,1.0,1.0);
  }
    else
        frag_color = vec4(1.0,1.0,1.0,1.0);
}

