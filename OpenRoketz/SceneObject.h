#pragma once

#include "ISceneObject.h"


class SceneObject : public ISceneObject
{
public:
  void setTextureName(std::string i_textureName);
  void setBehavior(ObjectBehavior i_behavior);

  // IInertial implementation

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
  virtual bool isCollidable() const override;
  virtual void setCollidable(bool i_collidable) override;
  virtual bool isRigid() const override;
  virtual void setRigid(bool i_rigid) override;

  virtual void addCollidedObject(std::shared_ptr<IInertial> i_object) override;
  virtual void clearCollidedObjects() override;

  // ISceneObject implementation

  virtual const std::string& getTextureName() const override;
  virtual ObjectBehavior getBehavior() const override;

private:
  Sdk::Vector2D d_position;

  std::string d_textureName;
  ObjectBehavior d_behavior = ObjectBehavior::Default;

  bool d_collidable = true;
  bool d_rigid = true;

  std::vector<std::shared_ptr<IInertial>> d_collidedObjects;
};
