#include "Patient.h"

std::ostream& operator<<(std::ostream& os, const Patient& patient)
{
    os << patient.getName();

    if (patient.m_doctors.empty())
    {
        os << " has no doctors right now";
        return os;
    }

    os << " is seeing doctors: ";
    for (const Doctor& doctor : patient.m_doctors)
    {
        os << doctor.getName() << ' ';
    }

    return os;
}