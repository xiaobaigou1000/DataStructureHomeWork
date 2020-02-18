#include<iostream>
#include<vector>
#include<array>
#include<glm.hpp>
#include<gtc/matrix_transform.hpp>
#include<gtc/type_ptr.hpp>

#include"LibTest.h"
#include"../BST Tree/FoolBST.h"
using std::cout;

int main() {
    using namespace glm;
    using std::cout;

    constexpr static std::array<float, 216> vertices =
    {
    -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
     0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
     0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
     0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
    -0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
    -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,

    -0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,
     0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,
     0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,
     0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,
    -0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,
    -0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,

    -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,
    -0.5f,  0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
    -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
    -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
    -0.5f, -0.5f,  0.5f, -1.0f,  0.0f,  0.0f,
    -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,

     0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,
     0.5f,  0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
     0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
     0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
     0.5f, -0.5f,  0.5f,  1.0f,  0.0f,  0.0f,
     0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,

    -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,
     0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,
     0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
     0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
    -0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
    -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,

    -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,
     0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,
     0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
     0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
    -0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
    -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f
    };

    for (int i = 0; i < 36; ++i)
    {
        mat4 translateMat{ 1.0f };
        mat4 scaleMat{ 1.0f };
        mat4 rotateMat{ 1.0f };

        translateMat = translate(translateMat, vec3{ 1.0f,2.0f,3.0f });
        scaleMat = scale(scaleMat, vec3{ 0.5f,0.5f,0.5f });
        rotateMat = rotate(rotateMat, radians(55.0f), vec3{ 0.5f,1.0f,0.0f });

        mat4 viewMat = lookAt(vec3{ 0.0f,0.0f,-3.0f }, vec3{ 0.0f }, vec3{ 0.0f,1.0f,0.0f });
        mat4 projection = perspective(45.0f, 800.0f / 800.0f, 0.1f, 100.0f);

        mat4 modelMat = translateMat * rotateMat * scaleMat;
        mat4 MVP = projection * viewMat * modelMat;

        vec3 position{ vertices[6*i+0],vertices[6 * i + 1],vertices[6 * i + 2] };
        vec3 inNormal{ vertices[6*i+3],vertices[6 * i + 4],vertices[6 * i + 5] };



        vec4 gl_Position = MVP * vec4{ position.x, position.y, position.z, 1.0f };
        vec3 Normal = mat3(transpose(inverse(modelMat))) * inNormal;
        vec3 FragPos = vec3(modelMat * vec4(position, 1.0f));


        vec3 lightColor{ 1.0f, 1.0f, 1.0f };
        vec3 objectColor{ 1.0f, 0.5f, 0.31f };
        vec3 lightPos{ 1.2f, 1.0f, 2.0f };

        float ambientStrength = 0.1f;
        vec3 ambient = ambientStrength * lightColor;

        vec3 norm = normalize(Normal);
        vec3 lightDir = normalize(lightPos - FragPos);
        float diff = max(dot(norm, lightDir), 0.0f);
        // float diff = dot(norm, lightDir);
        vec3 diffuse = diff * lightColor;

        vec3 result = (ambient + diffuse) * objectColor;
        vec4 Frag_Color = vec4(result, 1.0f);

        cout << result.x << ' ' << result.y << ' ' << result.z<<'\n';
    }


    mat4 translateMat{ 1.0f };
    mat4 scaleMat{ 1.0f };
    mat4 rotateMat{ 1.0f };

    translateMat = translate(translateMat, vec3{ 1.0f,2.0f,3.0f });
    scaleMat = scale(scaleMat, vec3{ 0.5f,0.5f,0.5f });
    rotateMat = rotate(rotateMat, radians(55.0f), vec3{ 0.5f,1.0f,0.0f });

    mat4 viewMat = lookAt(vec3{ 0.0f,0.0f,-3.0f }, vec3{ 0.0f }, vec3{ 0.0f,1.0f,0.0f });
    mat4 projection = perspective(45.0f, 800.0f / 800.0f, 0.1f, 100.0f);

    mat4 modelMat = translateMat * rotateMat * scaleMat;
    mat4 MVP = projection * viewMat * modelMat;

    vec3 position{ -0.5f, -0.5f, -0.5f };
    vec3 inNormal{ 0.0f,  0.0f, -1.0f };



    vec4 gl_Position = MVP * vec4{ position.x, position.y, position.z, 1.0f };
    vec3 Normal = mat3(transpose(inverse(modelMat))) * inNormal;
    vec3 FragPos = vec3(modelMat * vec4(position, 1.0f));


    vec3 lightColor{ 1.0f, 1.0f, 1.0f };
    vec3 objectColor{ 1.0f, 0.5f, 0.31f };
    vec3 lightPos{ 1.2f, 1.0f, 2.0f };

    float ambientStrength = 0.1f;
    vec3 ambient = ambientStrength * lightColor;

    vec3 norm = normalize(Normal);
    vec3 lightDir = normalize(lightPos - FragPos);
    float diff = max(dot(norm, lightDir), 0.0f);
    // float diff = dot(norm, lightDir);
    vec3 diffuse = diff * lightColor;

    vec3 result = (ambient + diffuse) * objectColor;
    vec4 Frag_Color = vec4(result, 1.0f);

    //cout << lightDir.x<<' '<< lightDir.y<<' '<< lightDir.z;

    return 0;
}