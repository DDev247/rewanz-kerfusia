#ifndef DDEV_REWANZ_KERFUSIA_REWANZ_KERFUSIA_APP_H
#define DDEV_REWANZ_KERFUSIA_REWANZ_KERFUSIA_APP_H

#include "delta.h"
#include "gameobject.h"

class RewanzKerfusiaApp {
public:
    RewanzKerfusiaApp();
    ~RewanzKerfusiaApp();

    static RewanzKerfusiaApp* instance;

    void Initialize(void *instance, ysContextObject::DeviceAPI api);
    void Run();
    void Destroy();

    dbasic::DeltaEngine m_engine;
    dbasic::AssetManager m_assetManager;
    dbasic::DefaultShaders m_shaders;

protected:
    void Process();
    void Render();

    dbasic::ShaderSet m_shaderSet;

    GameObject m_kerfus0;
    GameObject m_kerfus1;
    GameObject m_kerfus2;

    ysTexture *m_demoTexture;
    float m_currentRotation;
    float m_temperature;
};

#endif /* DDEV_REWANZ_KERFUSIA_REWANZ_KERFUSIA_APP_H */
