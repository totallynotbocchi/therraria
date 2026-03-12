#include "Physics.hpp"
using namespace therraria;

Physics::Physics(uint16_t gravity)
    : m_Gravity(gravity)
{
}

void Physics::ApplyGravity(float_t dt, PhysicsBody& body)
{
  body.GetPosition().y += dt * m_Gravity;
}
