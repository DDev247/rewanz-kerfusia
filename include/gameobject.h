#ifndef DDEV_REWANZ_KERFUSIA_GAMEOBJECT_H
#define DDEV_REWANZ_KERFUSIA_GAMEOBJECT_H

#include "delta.h"

class GameObject {
public:
    GameObject();
    ~GameObject();

    void Initialize(std::string modelName);
    void Run();

    ysVector m_position = ysMath::LoadVector(0,0,0);
    ysMatrix m_rotation = ysMath::RotationTransform(ysMath::Constants::XAxis, 0);

    float m_scaleX = 0.5F;
    float m_scaleY = 0.5F;
    float m_scaleZ = 0.5F;

    std::string m_modelName = "Cube";
    std::string m_materialName = "";

protected:
    void Process();
    void Render();
};

#endif /* DDEV_REWANZ_KERFUSIA_GAMEOBJECT_H */
