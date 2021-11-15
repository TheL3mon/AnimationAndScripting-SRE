//
// Created by Morten Nobel-Jørgensen on 11/6/17.
//

#include <iostream>
#include "BirdMovementComponent.hpp"
#include "GameObject.hpp"

BirdMovementComponent::BirdMovementComponent(GameObject *gameObject) : Component(gameObject) {}

void BirdMovementComponent::update(float deltaTime) {
    time += deltaTime;
    gameObject->setPosition(computePositionAtTime(time));
}

glm::vec2 BirdMovementComponent::computePositionAtTime(float time) {
    int segment = (int)fmod(time, getNumberOfSegments());
    float t = fmod(time,1.0f);

    // todo use Quadratic Bézier spline instead
    positions[segment].x = glm::pow(1 - segment, 2) * positions[segment].x + 2 * segment * (1 - segment) * positions[segment + 1].x + glm::pow(segment, 2) * positions[segment + 2].x;
    positions[segment].y = glm::pow(1 - segment, 2) * positions[segment].y + 2 * segment * (1 - segment) * positions[segment + 1].y + glm::pow(segment, 2) * positions[segment + 2].y;
    
    return glm::mix(positions[segment], positions[segment + 1], t);
}

const std::vector<glm::vec2> &BirdMovementComponent::getPositions() {
    return positions;
}

void BirdMovementComponent::setPositions(std::vector<glm::vec2> positions) {
    this->positions = std::move(positions);
}

int BirdMovementComponent::getNumberOfSegments() {
    // todo return number of Quadratic Bézier spline segments instead
    return positions.size()-1;
}

