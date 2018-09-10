#include "TestAnalysis.h"

#include <iostream>
using std::cerr;
using std::cout;
using std::endl;

#include <TClonesArray.h>

#include "DetEventFull.h"
#include "DetEventStation.h"
#include "DetMessage.h"

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
		if (curName == "Left_telescope") {
			fLteleSubEl = (TGo4CompositeEvent*)(fSubElements[i]);
		}
	}

	////Short_t rtNsubsubElems = fRteleSubEl->getNElements();

	fSubsubEl_CsI_R  = (DetEventStation*)fRteleSubEl->getEventElement("Right_telescope_CsI_R");
	fSubsubEl_SQX_R  = (DetEventStation*)fRteleSubEl->getEventElement("Right_telescope_SQX_R");
	fSubsubEl_SQY_R  = (DetEventStation*)fRteleSubEl->getEventElement("Right_telescope_SQY_R");
	fSubsubEl_tCsI_R = (DetEventStation*)fRteleSubEl->getEventElement("Right_telescope_tCsI_R");
	fSubsubEl_tSQX_R = (DetEventStation*)fRteleSubEl->getEventElement("Right_telescope_tSQX_R");
	fSubsubEl_tSQY_R = (DetEventStation*)fRteleSubEl->getEventElement("Right_telescope_tSQY_R");

	fSubsubEl_CsI_L = (DetEventStation*)fLteleSubEl->getEventElement("Left_telescope_CsI_L");
	fSubsubEl_SQX_L = (DetEventStation*)fLteleSubEl->getEventElement("Left_telescope_SQX_L");
	fSubsubEl_SQY_L = (DetEventStation*)fLteleSubEl->getEventElement("Left_telescope_SQY_L");
	fSubsubEl_tCsI_L = (DetEventStation*)fLteleSubEl->getEventElement("Left_telescope_tCsI_L");
	fSubsubEl_tSQX_L = (DetEventStation*)fLteleSubEl->getEventElement("Left_telescope_tSQX_L");
	fSubsubEl_tSQY_L = (DetEventStation*)fLteleSubEl->getEventElement("Left_telescope_tSQY_L");
	fSubsubEl_tSQ300 = (DetEventStation*)fLteleSubEl->getEventElement("Left_telescope_tSQ300");
	fSubsubEl_SQ300 = (DetEventStation*)fLteleSubEl->getEventElement("Left_telescope_SQ300");


	if (fSubsubEl_CsI_R == NULL  || fSubsubEl_SQX_R == NULL  || fSubsubEl_SQY_R == NULL ||
		fSubsubEl_tCsI_R == NULL || fSubsubEl_tSQX_R == NULL || fSubsubEl_tSQY_R == NULL ||
		fSubsubEl_CsI_L == NULL || fSubsubEl_SQX_L == NULL || fSubsubEl_SQY_L == NULL ||
		fSubsubEl_tCsI_L == NULL || fSubsubEl_tSQX_L == NULL || fSubsubEl_tSQY_L == NULL ||
		fSubsubEl_tSQ300 == NULL || fSubsubEl_SQ300 == NULL)
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

	TClonesArray* CsI_L_clar = fSubsubEl_CsI_L->GetDetMessages();
	TClonesArray* SQX_L_clar = fSubsubEl_SQX_L->GetDetMessages();
	TClonesArray* SQY_L_clar = fSubsubEl_SQY_L->GetDetMessages();
	TClonesArray* tCsI_L_clar = fSubsubEl_tCsI_L->GetDetMessages();
	TClonesArray* tSQX_L_clar = fSubsubEl_tSQX_L->GetDetMessages();
	TClonesArray* tSQY_L_clar = fSubsubEl_tSQY_L->GetDetMessages();
	TClonesArray* tSQ300_clar = fSubsubEl_tSQ300->GetDetMessages();
	TClonesArray* SQ300_clar = fSubsubEl_SQ300->GetDetMessages();


	// cerr << "CsI_R: " << CsI_R_clar->GetEntries() << endl;
	// cerr << "SQX_R: " << SQX_R_clar->GetEntries() << endl;
	// cerr << "SQY_R: " << SQY_R_clar->GetEntries() << endl;
	// cerr << "tCsI_R: " << tCsI_R_clar->GetEntries() << endl;
	// cerr << "tSQX_R: " << tSQX_R_clar->GetEntries() << endl;
	// cerr << "tSQY_R: " << tSQY_R_clar->GetEntries() << endl;
	// cerr << "CsI_L: " << CsI_L_clar->GetEntries() << endl;
	// cerr << "SQX_L: " << SQX_L_clar->GetEntries() << endl;
	// cerr << "SQY_L: " << SQY_L_clar->GetEntries() << endl;
	// cerr << "tCsI_L: " << tCsI_L_clar->GetEntries() << endl;
	// cerr << "tSQX_L: " << tSQX_L_clar->GetEntries() << endl;
	// cerr << "tSQY_L: " << tSQY_L_clar->GetEntries() << endl;
	// cerr << "SQ300: " << SQ300_clar->GetEntries() << endl;
	// cerr << "tSQ300: " << tSQ300_clar->GetEntries() << endl;


	DetMessage *SQY_R[16];
	for(Int_t i=0;i<16;i++){
		SQY_R[i] = (DetMessage*)SQY_R_clar->At(i);
		cout << SQY_R[i]->GetStChannel() << " "  << SQY_R[i]->GetValue() << endl;
	}


/*

	Int_t GetStChannel(void) const { return fStChannel; }

	Int_t GetValue(void) const { return fValue; }
*/

	// for(Int_t i = 0; i < SQX_R_clar->GetEntries(); i++){
	// 	cout << (DetMessage*)SQX_R_clar->At(i)->GetStChannel() << " " <<(DetMessage*)SQX_R_clar->At(i)->GetValue() << endl;
	// }


}

ClassImp(TestAnalysis)
