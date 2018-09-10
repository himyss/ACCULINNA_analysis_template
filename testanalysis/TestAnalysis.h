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
	TGo4CompositeEvent* fLteleSubEl;

	DetEventStation* fSubsubEl_CsI_R;
	DetEventStation* fSubsubEl_SQX_R;
	DetEventStation* fSubsubEl_SQY_R;
	DetEventStation* fSubsubEl_tCsI_R;
	DetEventStation* fSubsubEl_tSQX_R;
	DetEventStation* fSubsubEl_tSQY_R;

	DetEventStation* fSubsubEl_CsI_L;
	DetEventStation* fSubsubEl_SQX_L;
	DetEventStation* fSubsubEl_SQY_L;
	DetEventStation* fSubsubEl_tCsI_L;
	DetEventStation* fSubsubEl_tSQX_L;
	DetEventStation* fSubsubEl_tSQY_L;
	DetEventStation* fSubsubEl_tSQ300;
	DetEventStation* fSubsubEl_SQ300;

	ClassDef(TestAnalysis, 1);
};

#endif // TESTANALYSIS_H
