
#include "../include/gameobject.h"
#include "../include/rewanz_kerfusia_app.h"

GameObject::GameObject() {}

GameObject::~GameObject() {}

void GameObject::Initialize(std::string modelName) {
	m_modelName = modelName;
}

void GameObject::Process() {

}

void GameObject::Render() {
	RewanzKerfusiaApp::instance->m_shaders.ResetBrdfParameters();

	if (m_materialName == "") {
		RewanzKerfusiaApp::instance->m_shaders.SetMetallic(0.8f);
		RewanzKerfusiaApp::instance->m_shaders.SetIncidentSpecular(0.8f);
		RewanzKerfusiaApp::instance->m_shaders.SetSpecularRoughness(0.7f);
		RewanzKerfusiaApp::instance->m_shaders.SetSpecularMix(1.0f);
		RewanzKerfusiaApp::instance->m_shaders.SetDiffuseMix(1.0f);
		RewanzKerfusiaApp::instance->m_shaders.SetBaseColor(ysColor::srgbiToLinear(0xef, 0xef, 0xef));
		RewanzKerfusiaApp::instance->m_shaders.SetColorReplace(true);
	}
	
	RewanzKerfusiaApp::instance->m_shaders.SetObjectTransform(ysMath::MatMult(ysMath::TranslationTransform(m_position), m_rotation));
	RewanzKerfusiaApp::instance->m_shaders.SetScale(m_scaleX, m_scaleY, m_scaleZ);
	RewanzKerfusiaApp::instance->m_engine.DrawModel(RewanzKerfusiaApp::instance->m_shaders.GetRegularFlags(), RewanzKerfusiaApp::instance->m_assetManager.GetModelAsset(m_modelName.c_str()));
}

void GameObject::Run() {
	Process();
	Render();
}
