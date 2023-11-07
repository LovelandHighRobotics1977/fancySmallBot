#include "Headers.h"
void Drive::TeleDrive(float left, float right)
{
  if (m_pdp.GetCurrent(16) < 10 && m_pdp.GetCurrent(17) < 10 &&
  m_pdp.GetCurrent(18) < 10 && m_pdp.GetCurrent(19) < 10)
  {
    m_l1.Set(left);
    m_l2.Set(left);
    m_r1.Set(right);
    m_r2.Set(right);
  }

  if (left == 0 && right == 0)
  {
    m_l1.SetNeutralMode(Brake);
    m_l2.SetNeutralMode(Brake);
    m_r1.SetNeutralMode(Brake);
    m_r2.SetNeutralMode(Brake);
  }
  else
  {
    m_l1.SetNeutralMode(Coast);
    m_l2.SetNeutralMode(Coast);
    m_r1.SetNeutralMode(Coast);
    m_r2.SetNeutralMode(Coast);
  }
};