// Implementing bidirectional association
// 5:01PM 06-Jan, 2023

#ifndef DOCTOR_H
#define DOCTOR_H

#include <functional>
#include <iostream>
#include <string>
#include <string_view>
#include <vector>

// forward declare to avoid circular dependency issues
class Patient;

class Doctor
{
private:
    std::string m_name{};
    std::vector<std::reference_wrapper<Patient>> m_patients{};

public:
    Doctor(std::string_view name) : m_name{name} {}

    std::string_view getName() const { return m_name; }

    // will add the doctor to the patient's doctor list and vice-versa
    void addPatient(Patient& patient);

    friend std::ostream& operator<<(std::ostream& os, const Doctor& doctor);
};

#endif