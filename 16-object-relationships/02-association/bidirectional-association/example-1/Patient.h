// Implementing bidirectional association
// 5:01PM 06-Jan, 2023

#ifndef PATIENT_H
#define PATIENT_H

// include Doctor
#include "Doctor.h"

#include <functional>
#include <iostream>
#include <string>
#include <string_view>
#include <vector>

// A Patient has a list(std::vector) of `Doctor`s that they visit, on top of
// having a name.
class Patient
{
private:
    std::string m_name{};
    std::vector<std::reference_wrapper<const Doctor>> m_doctors{};

    // A `Patient`s Doctor list cannot be edited by anyone else
    void addDoctor(const Doctor& doctor) { m_doctors.push_back(doctor); }

public:
    Patient(std::string_view name) : m_name{name} {}

    std::string_view getName() const { return m_name; }

    friend void Doctor::addPatient(Patient& patient);
    friend std::ostream& operator<<(std::ostream& os, const Patient& patient);
};

#endif