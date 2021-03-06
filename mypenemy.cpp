#include "mypenemy.h"

MyPEnemy::MyPEnemy(int xPosition, int yPosition, float strength, std::shared_ptr<std::vector<std::shared_ptr<QImage>>> idle_animations, std::shared_ptr<std::vector<std::shared_ptr<QImage>>> death_animations, std::shared_ptr<std::vector<std::shared_ptr<QImage>>> walking_animations):
    Entity(xPosition, yPosition, strength, idle_animations,death_animations,walking_animations), poisonLevel{strength}
{
  qsrand(time(nullptr));
}

bool MyPEnemy::poison()
{
  if (poisonLevel > 0.0f)
    {
      emit poisonLevelUpdated(poisonLevel, xPos,yPos);
      int t = qrand()%5;
      poisonLevel -= 10.0f;
      QTimer::singleShot(t*1000, this, SLOT(poison()));
      return true;
    }
  else
    {
      poisonLevel = 0.0f;
      emit poisonLevelUpdated(poisonLevel, xPos, yPos);
      emit dead();
    }
  return false;
}

float MyPEnemy::getPoisonLevel() const
{
  return poisonLevel;
}

void PEnemy::setPoisonLevel(float newvalue)
{
  poisonLevel = newvalue;
}

QString MyPEnemy::getTextRepresentation()
{
    if(state == EntityState::DEFEATED) return "<span style=\"color:black; font-family: monospace;  white-space: pre;\"> x </span>";
    else
    {
        QString value;
        if(int(this->getValue()) < 10) value.append("0");
        value.append(QString::fromStdString(std::to_string(int(this->getValue()))));

        QString text = "<span style=\"color:purple; font-family: monospace;  white-space: pre; font-weight: 900;\">P</span>";
        text.append("<span style=\"color:black; font-family: monospace;  white-space: pre; font-weight: 100;\">");
        text.append(value);
        text.append("</span>");
        return text;
    }
}
