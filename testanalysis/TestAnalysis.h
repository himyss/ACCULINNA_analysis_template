#ifndef TESTANALYSIS_H
#define TESTANALYSIS_H

#include <TObject.h> // mother class

class TGo4CompositeEvent;
class TGo4EventElement;

class DetEventFull;
class DetEventStation;

class TestAnalysis : public TObject
{
public:
	TestAnalysis();
	virtual ~TestAnalysis();

	void Init(DetEventFull* curEvent);

	void ProcessEvent(DetEventFull* curEvent);

private:

	Short_t fNsubElems;

	TGo4EventElement** fSubElements; //[fNsubElems]

	TGo4CompositeEvent* fRteleSubEl;

	DetEventStation* fSubsubEl_CsI_R;
	DetEventStation* fSubsubEl_SQX_R;
	DetEventStation* fSubsubEl_SQY_R;
	DetEventStation* fSubsubEl_tCsI_R;
	DetEventStation* fSubsubEl_tSQX_R;
	DetEventStation* fSubsubEl_tSQY_R;

	ClassDef(TestAnalysis, 1);
};

#endif // TESTANALYSIS_H
