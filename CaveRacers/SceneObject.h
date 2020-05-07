#pragma once

#include "ISceneObject.h"


class SceneObject : public ISceneObject
{
public:
  SceneObject();

  void setMass(double i_mass);

  void setTextureName(std::string i_textureName);
  void setBehavior(ObjectBehavior i_behavior);
  void setRect(Sdk::RectD i_rect);
  void setSendCollision(bool i_sendCollision);
  void setReceiveCollision(bool i_receiveCollision);
  void setRigid(bool i_rigid);

  // IInertial implementation

  virtual double getMaxSpeed() const override;
  virtual double getMass() const override;

  virtual const Sdk::Vector2D& getPosition() const override;
  virtual void setPosition(Sdk::Vector2D i_position) override;

  virtual const Sdk::Vector2D& getSpeed() const override;
  virtual void setSpeed(Sdk::Vector2D i_speed) override;

  virtual double getRotation() const override;
  virtual void setRotation(double i_rotation) override;

  virtual double getRotationSpeed() const override;
  virtual void setRotationSpeed(double i_rotationSpeed) override;

  virtual void addActiveForce(Force i_force) override;
  virtual const std::vector<Force>& getActiveForces() const override;
  virtual void clearActiveForces() override;

  virtual bool isGravityAffected() const override;
  virtual void setGravityAffected(bool i_affected) override;

  virtual Sdk::RectD getRect() const override;
  virtual bool isReceiveCollision() const override;
  virtual bool isSendCollision() const override;
  virtual bool isRigid() const override;

  virtual void addCollision(CollisionInfo i_collisionInfo) override;
  virtual const std::vector<CollisionInfo>& getCollisions() const override;
  virtual void clearCollisions() override;

  // ISceneObject implementation

  virtual void update(double i_dt) override;

  virtual const std::string& getTextureName() const override;
  virtual ObjectBehavior getBehavior() const override;

private:
  Sdk::Vector2D d_position;
  Sdk::Vector2D d_speed;
  Sdk::RectD d_rect;

  double d_rotation = 0.0;

  std::string d_textureName;
  ObjectBehavior d_behavior = ObjectBehavior::Default;

  double d_mass = 0;

  bool d_collidable = true;
  bool d_gravityAffected = false;
  bool d_rigid = true;
  bool d_sendCollision = true;
  bool d_receiveCollision = true;

  std::vector<CollisionInfo> d_collisions;
};
