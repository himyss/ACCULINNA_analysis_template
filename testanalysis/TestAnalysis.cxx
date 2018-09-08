#include "TestAnalysis.h"

#include <iostream>
using std::cerr;
using std::endl;

#include <TClonesArray.h>

#include "DetEventFull.h"
#include "DetEventStation.h"

TestAnalysis::TestAnalysis() :
	TObject(),
	fNsubElems(0),
	fSubElements(nullptr)
{
}

TestAnalysis::~TestAnalysis()
{
	if (fSubElements) { delete [] fSubElements; fSubElements = nullptr; }
}

//TestAnalysis::Init
// used only once for the whole input tree
// Establishes a correspondence between the input tree and the TestAnalysis stations, which contains TClonesArray with signals
// (similar to SetBranchAdress)
void TestAnalysis::Init(DetEventFull* curEvent)
{
	fNsubElems = curEvent->getNElements();

	fSubElements = new TGo4EventElement*[fNsubElems];

	for (Short_t i=0; i<fNsubElems; i++) {
		fSubElements[i] = curEvent->getEventElement(i);

		TString curName = fSubElements[i]->GetName();
		if (curName == "Right_telescope") {
			fRteleSubEl = (TGo4CompositeEvent*)(fSubElements[i]);
		}
	}

	////Short_t rtNsubsubElems = fRteleSubEl->getNElements();

	fSubsubEl_CsI_R  = (DetEventStation*)fRteleSubEl->getEventElement("Right_telescope_CsI_R");
	fSubsubEl_SQX_R  = (DetEventStation*)fRteleSubEl->getEventElement("Right_telescope_SQX_R");
	fSubsubEl_SQY_R  = (DetEventStation*)fRteleSubEl->getEventElement("Right_telescope_SQY_R");
	fSubsubEl_tCsI_R = (DetEventStation*)fRteleSubEl->getEventElement("Right_telescope_tCsI_R");
	fSubsubEl_tSQX_R = (DetEventStation*)fRteleSubEl->getEventElement("Right_telescope_tSQX_R");
	fSubsubEl_tSQY_R = (DetEventStation*)fRteleSubEl->getEventElement("Right_telescope_tSQY_R");

	if (fSubsubEl_CsI_R == NULL  || fSubsubEl_SQX_R == NULL  || fSubsubEl_SQY_R == NULL ||
		fSubsubEl_tCsI_R == NULL || fSubsubEl_tSQX_R == NULL || fSubsubEl_tSQY_R == NULL)
	{
		cerr << "ERROR" << endl;
		exit(EXIT_FAILURE);
	}
}

// processing single event data
void TestAnalysis::ProcessEvent(DetEventFull* curEvent)
{
	TClonesArray* CsI_R_clar = fSubsubEl_CsI_R->GetDetMessages();
	TClonesArray* SQX_R_clar = fSubsubEl_SQX_R->GetDetMessages();
	TClonesArray* SQY_R_clar = fSubsubEl_SQY_R->GetDetMessages();
	TClonesArray* tCsI_R_clar = fSubsubEl_tCsI_R->GetDetMessages();
	TClonesArray* tSQX_R_clar = fSubsubEl_tSQX_R->GetDetMessages();
	TClonesArray* tSQY_R_clar = fSubsubEl_tSQY_R->GetDetMessages();

	cerr << "CsI_R: " << CsI_R_clar->GetEntries() << endl;
	cerr << "SQX_R: " << SQX_R_clar->GetEntries() << endl;
	cerr << "SQY_R: " << SQY_R_clar->GetEntries() << endl;
	cerr << "tCsI_R: " << tCsI_R_clar->GetEntries() << endl;
	cerr << "tSQX_R: " << tSQX_R_clar->GetEntries() << endl;
	cerr << "tSQY_R: " << tSQY_R_clar->GetEntries() << endl;
}

ClassImp(TestAnalysis)
