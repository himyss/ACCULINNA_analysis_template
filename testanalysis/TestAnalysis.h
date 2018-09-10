#ifndef TESTANALYSIS_H
#define TESTANALYSIS_H

#include <TObject.h> // mother class

class TGo4CompositeEvent;
class TGo4EventElement;

class DetEventFull;
class DetEventStation;

class TClonesArray;

class TestAnalysis : public TObject
{
public:
	TestAnalysis();
	virtual ~TestAnalysis();

	void Init(DetEventFull* curEvent);

	void ProcessEvent();

private:

	const TClonesArray* fCsI_R_clar;
	const TClonesArray* fSQX_R_clar;
	const TClonesArray* fSQY_R_clar;
	const TClonesArray* ftCsI_R_clar;
	const TClonesArray* ftSQX_R_clar;
	const TClonesArray* ftSQY_R_clar;
	const TClonesArray* fCsI_L_clar;
	const TClonesArray* fSQX_L_clar;
	const TClonesArray* fSQY_L_clar;
	const TClonesArray* ftCsI_L_clar;
	const TClonesArray* ftSQX_L_clar;
	const TClonesArray* ftSQY_L_clar;
	const TClonesArray* ftSQ300_clar;
	const TClonesArray* fSQ300_clar;


	ClassDef(TestAnalysis, 1);
};

#endif // TESTANALYSIS_H
