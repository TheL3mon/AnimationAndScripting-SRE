#pragma once

#include "Component.hpp"
#include "sre/Sprite.hpp"

class SpriteComponent : public Component {
public:
    explicit SpriteComponent(GameObject *gameObject);

    void renderSprite(sre::SpriteBatch::SpriteBatchBuilder &spriteBatchBuilder) override;

    void setSprite(const sre::Sprite& sprite);
    sre::Sprite getSprite();

    void flipSprite(glm::bvec2 boolVec);
private:
    sre::Sprite sprite;
};

