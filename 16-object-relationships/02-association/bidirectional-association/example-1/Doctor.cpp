#include "Doctor.h"

// include to work with the type
#include "Patient.h"

void Doctor::addPatient(Patient& patient)
{
    m_patients.push_back(patient);
    patient.addDoctor(*this);
}

std::ostream& operator<<(std::ostream& os, const Doctor& doctor)
{
    os << doctor.getName();
    if (doctor.m_patients.empty())
    {
        os << " has no patients right now";
        return os;
    }

    os << " is seeing patients: ";
    for (const Patient& patient : doctor.m_patients)
    {
        os << patient.getName() << ' ';
    }

    return os;
}