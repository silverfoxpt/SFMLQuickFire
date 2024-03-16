#version 330 core
out vec4 FragColor;

in vec3 ourColor;
in vec2 TexCoord;

uniform sampler2D ourTexture;
uniform sampler2D newTexture;

void main()
{
   //FragColor = vec4(ourColor, 1.0f);
   //FragColor = texture(ourTexture, TexCoord) * vec4(ourColor, 1.0);
   FragColor = mix(texture(ourTexture, TexCoord), texture(newTexture, 
      vec2(TexCoord.x, TexCoord.y)), 0.2) * vec4(ourColor, 1.0f);
   //FragColor = texture(newTexture, TexCoord);
}