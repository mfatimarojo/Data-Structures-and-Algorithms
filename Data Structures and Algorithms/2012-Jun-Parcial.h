/*
Create a Clinic TAD that simulates the behavior of a clinic office with the following functionalities:
- EmptyClinic: creates a new empty Clinic
- newDoctor: sings up a new Doctor to the Clinic
- makeAppointment: a Patient is added to the line to be attended by the Doctor
- makeAppointmentWithRef: a Patient is added to the beginning of the line to be attended first by the Doctor
- hasPatients: informs if a Doctor has still Patients waiting.
- nextPatient: shows the following patient to be attended by the doctor.
- endSession: removes a patient from the line as he/she has been attended.
- numAppointments: shows the number of appointments of a Patient
*/

#ifndef __CLINIC_H
#define __CLINIC_H

#include <iostream>
#include <string>
#include "TADs/DiccionarioHash.h"
#include "TADs/dcola.h"

using namespace std;
typedef string Doctor;
typedef string Patient;

class Clinic {
public:

	// Creates a new empty Clinic
	Clinic() {}

	void newDoctor(const Doctor &D) {
		if (!_doctorPatients.contiene(D)) {
			DCola<Patient> patients;
			_doctorPatients.inserta(D, patients);
		}
	}

	void makeAppointment(const Patient& P, const Doctor &D) {
		if (_doctorPatients.contiene(D)) {
			_doctorPatients.busca(D).valor().pon_final(P);
			if (_patientAppointments.contiene(P)) {
				int appointments = _patientAppointments.valorPara(P);
				_patientAppointments.busca(P).setVal(appointments + 1);
			}
			else _patientAppointments.inserta(P, 1);
		}
	}

	void makeAppointmentWithRef(const Patient& P, const Doctor& D) {
		if (_doctorPatients.contiene(D)) {
			_doctorPatients.busca(D).valor().pon_ppio(P);
			if (_patientAppointments.contiene(P)) {
				int appointments = _patientAppointments.valorPara(P);
				_patientAppointments.busca(P).setVal(appointments + 1);
			}
			else _patientAppointments.inserta(P, 1);
		}
	}

	const bool hasPatients(const Doctor& D) const {
		if (!_doctorPatients.contiene(D)) return false;
		return (!_doctorPatients.valorPara(D).esVacia());
	}

	const Patient nextPatient(const Doctor& D) const {
		if (!_doctorPatients.contiene(D) ) return NULL;
		return _doctorPatients.valorPara(D).primero();
	}

	void endSession(const Doctor& D) {
		if (_doctorPatients.contiene(D) && !_doctorPatients.valorPara(D).esVacia()) {
			Patient P = _doctorPatients.valorPara(D).primero();
			_doctorPatients.busca(D).valor().quita_ppio();
			if (!_patientAppointments.contiene(P)) {
				int appointments = _patientAppointments.valorPara(P);
				if (appointments > 1) {
					_patientAppointments.busca(P).setVal(appointments - 1);
				}
				else {
					_patientAppointments.borra(P);
				}
			}
		}
	}

	const int numAppointments(const Patient& P) const {
		if (!_patientAppointments.contiene(P)) return 0;
		return _patientAppointments.valorPara(P);
	}

	~Clinic() {}

private:
	DiccionarioHash<Doctor, DCola<Patient>> _doctorPatients;
	DiccionarioHash<Patient, int> _patientAppointments;
};

#endif