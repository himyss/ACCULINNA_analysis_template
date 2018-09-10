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
	fCsI_R_clar(nullptr),
	fSQX_R_clar(nullptr),
	fSQY_R_clar(nullptr),
	ftCsI_R_clar(nullptr),
	ftSQX_R_clar(nullptr),
	ftSQY_R_clar(nullptr),
	fCsI_L_clar(nullptr),
	fSQX_L_clar(nullptr),
	fSQY_L_clar(nullptr),
	ftCsI_L_clar(nullptr),
	ftSQX_L_clar(nullptr),
	ftSQY_L_clar(nullptr),
	ftSQ300_clar(nullptr),
	fSQ300_clar(nullptr)
{
	cout << "TestAnalysis constructor called!" << endl; 
}

TestAnalysis::~TestAnalysis()
{
	if(fCsI_R_clar) delete fCsI_R_clar;
	if(fSQX_R_clar) delete fSQX_R_clar;
	if(fSQY_R_clar) delete fSQY_R_clar;
	if(ftCsI_R_clar) delete ftCsI_R_clar;
	if(ftSQX_R_clar) delete ftSQX_R_clar;
	if(ftSQY_R_clar) delete ftSQY_R_clar;
	if(fCsI_L_clar) delete fCsI_L_clar;
	if(fSQX_L_clar) delete fSQX_L_clar;
	if(fSQY_L_clar) delete fSQY_L_clar;
	if(ftCsI_L_clar) delete ftCsI_L_clar;
	if(ftSQX_L_clar) delete ftSQX_L_clar;
	if(ftSQY_L_clar) delete ftSQY_L_clar;
	if(ftSQ300_clar) delete ftSQ300_clar;
	if(fSQ300_clar) delete fSQ300_clar;
	cout << "TestAnalysis destructor called!" << endl; 
}

//TestAnalysis::Init
// used only once for the whole input tree
// Establishes a correspondence between the input tree and the TestAnalysis stations, which contains TClonesArray with signals
// (similar to SetBranchAdress)
void TestAnalysis::Init(DetEventFull* curEvent)
{

	Short_t NsubElems = curEvent->getNElements();;

	TGo4EventElement** SubElements = new TGo4EventElement*[NsubElems];

	TGo4CompositeEvent* RteleSubEl;
	TGo4CompositeEvent* LteleSubEl;

	DetEventStation* SubsubEl_CsI_R;
	DetEventStation* SubsubEl_SQX_R;
	DetEventStation* SubsubEl_SQY_R;
	DetEventStation* SubsubEl_tCsI_R;
	DetEventStation* SubsubEl_tSQX_R;
	DetEventStation* SubsubEl_tSQY_R;

	DetEventStation* SubsubEl_CsI_L;
	DetEventStation* SubsubEl_SQX_L;
	DetEventStation* SubsubEl_SQY_L;
	DetEventStation* SubsubEl_tCsI_L;
	DetEventStation* SubsubEl_tSQX_L;
	DetEventStation* SubsubEl_tSQY_L;
	DetEventStation* SubsubEl_tSQ300;
	DetEventStation* SubsubEl_SQ300;

	for (Short_t i=0; i<NsubElems; i++) {
		SubElements[i] = curEvent->getEventElement(i);

		TString curName = SubElements[i]->GetName();
		if (curName == "Right_telescope") {
			RteleSubEl = (TGo4CompositeEvent*)(SubElements[i]);
		}
		if (curName == "Left_telescope") {
			LteleSubEl = (TGo4CompositeEvent*)(SubElements[i]);
		}
	}

	////Short_t rtNsubsubElems = fRteleSubEl->getNElements();

	SubsubEl_CsI_R  = (DetEventStation*)RteleSubEl->getEventElement("Right_telescope_CsI_R");
	SubsubEl_SQX_R  = (DetEventStation*)RteleSubEl->getEventElement("Right_telescope_SQX_R");
	SubsubEl_SQY_R  = (DetEventStation*)RteleSubEl->getEventElement("Right_telescope_SQY_R");
	SubsubEl_tCsI_R = (DetEventStation*)RteleSubEl->getEventElement("Right_telescope_tCsI_R");
	SubsubEl_tSQX_R = (DetEventStation*)RteleSubEl->getEventElement("Right_telescope_tSQX_R");
	SubsubEl_tSQY_R = (DetEventStation*)RteleSubEl->getEventElement("Right_telescope_tSQY_R");

	SubsubEl_CsI_L = (DetEventStation*)LteleSubEl->getEventElement("Left_telescope_CsI_L");
	SubsubEl_SQX_L = (DetEventStation*)LteleSubEl->getEventElement("Left_telescope_SQX_L");
	SubsubEl_SQY_L = (DetEventStation*)LteleSubEl->getEventElement("Left_telescope_SQY_L");
	SubsubEl_tCsI_L = (DetEventStation*)LteleSubEl->getEventElement("Left_telescope_tCsI_L");
	SubsubEl_tSQX_L = (DetEventStation*)LteleSubEl->getEventElement("Left_telescope_tSQX_L");
	SubsubEl_tSQY_L = (DetEventStation*)LteleSubEl->getEventElement("Left_telescope_tSQY_L");
	SubsubEl_tSQ300 = (DetEventStation*)LteleSubEl->getEventElement("Left_telescope_tSQ300");
	SubsubEl_SQ300 = (DetEventStation*)LteleSubEl->getEventElement("Left_telescope_SQ300");


	if (SubsubEl_CsI_R == NULL  || SubsubEl_SQX_R == NULL  || SubsubEl_SQY_R == NULL ||
		SubsubEl_tCsI_R == NULL || SubsubEl_tSQX_R == NULL || SubsubEl_tSQY_R == NULL ||
		SubsubEl_CsI_L == NULL || SubsubEl_SQX_L == NULL || SubsubEl_SQY_L == NULL ||
		SubsubEl_tCsI_L == NULL || SubsubEl_tSQX_L == NULL || SubsubEl_tSQY_L == NULL ||
		SubsubEl_tSQ300 == NULL || SubsubEl_SQ300 == NULL)
	{
		cerr << "ERROR" << endl;
		exit(EXIT_FAILURE);
	}

	fCsI_R_clar = SubsubEl_CsI_R->GetDetMessages();
	fSQX_R_clar = SubsubEl_SQX_R->GetDetMessages();
	fSQY_R_clar = SubsubEl_SQY_R->GetDetMessages();
	ftCsI_R_clar = SubsubEl_tCsI_R->GetDetMessages();
	ftSQX_R_clar = SubsubEl_tSQX_R->GetDetMessages();
	ftSQY_R_clar = SubsubEl_tSQY_R->GetDetMessages();
	fCsI_L_clar = SubsubEl_CsI_L->GetDetMessages();
	fSQX_L_clar = SubsubEl_SQX_L->GetDetMessages();
	fSQY_L_clar = SubsubEl_SQY_L->GetDetMessages();
	ftCsI_L_clar = SubsubEl_tCsI_L->GetDetMessages();
	ftSQX_L_clar = SubsubEl_tSQX_L->GetDetMessages();
	ftSQY_L_clar = SubsubEl_tSQY_L->GetDetMessages();
	ftSQ300_clar = SubsubEl_tSQ300->GetDetMessages();
	fSQ300_clar = SubsubEl_SQ300->GetDetMessages();
}

// processing single event data
void TestAnalysis::ProcessEvent()
{

	DetMessage **SQY_R = new DetMessage*[fSQY_R_clar->GetEntries()];
	for(Int_t i=0;i<fSQY_R_clar->GetEntries();i++){
		SQY_R[i] = (DetMessage*)fSQY_R_clar->At(i);
	}

	DetMessage **tSQY_R = new DetMessage*[ftSQY_R_clar->GetEntries()];
	for(Int_t i=0;i<ftSQY_R_clar->GetEntries();i++){
		tSQY_R[i] = (DetMessage*)ftSQY_R_clar->At(i);
	}

	DetMessage **SQX_R = new DetMessage*[fSQX_R_clar->GetEntries()];
	for(Int_t i=0;i<fSQX_R_clar->GetEntries();i++){
		SQX_R[i] = (DetMessage*)fSQX_R_clar->At(i);
		// cout << SQX_R[i]->GetValue() << " " << endl;s 
	}

	DetMessage **tSQX_R = new DetMessage*[ftSQX_R_clar->GetEntries()];
	for(Int_t i=0;i<ftSQX_R_clar->GetEntries();i++){
		tSQX_R[i] = (DetMessage*)ftSQX_R_clar->At(i);
	}

	DetMessage **CsI_R = new DetMessage*[fCsI_R_clar->GetEntries()];
	for(Int_t i=0;i<fCsI_R_clar->GetEntries();i++){
		CsI_R[i] = (DetMessage*)fCsI_R_clar->At(i);
	}

	DetMessage **tCsI_R = new DetMessage*[ftCsI_R_clar->GetEntries()];
	for(Int_t i=0;i<ftCsI_R_clar->GetEntries();i++){
		tCsI_R[i] = (DetMessage*)ftCsI_R_clar->At(i);
	}

	DetMessage **CsI_L = new DetMessage*[fCsI_L_clar->GetEntries()];
	for(Int_t i=0;i<fCsI_L_clar->GetEntries();i++){
		CsI_L[i] = (DetMessage*)fCsI_L_clar->At(i);
	}

	DetMessage **tCsI_L = new DetMessage*[ftCsI_L_clar->GetEntries()];
	for(Int_t i=0;i<ftCsI_L_clar->GetEntries();i++){
		tCsI_L[i] = (DetMessage*)ftCsI_L_clar->At(i);
	}

	DetMessage **SQX_L = new DetMessage*[fSQX_L_clar->GetEntries()];
	for(Int_t i=0;i<fSQX_L_clar->GetEntries();i++){
		SQX_L[i] = (DetMessage*)fSQX_L_clar->At(i);
	}

	DetMessage **tSQX_L = new DetMessage*[ftSQX_L_clar->GetEntries()];
	for(Int_t i=0;i<ftSQX_L_clar->GetEntries();i++){
		tSQX_L[i] = (DetMessage*)ftSQX_L_clar->At(i);
	}

	DetMessage **SQY_L = new DetMessage*[fSQY_L_clar->GetEntries()];
	for(Int_t i=0;i<fSQY_L_clar->GetEntries();i++){
		SQY_L[i] = (DetMessage*)fSQY_L_clar->At(i);
	}

	DetMessage **tSQY_L = new DetMessage*[ftSQY_L_clar->GetEntries()];
	for(Int_t i=0;i<ftSQY_L_clar->GetEntries();i++){
		tSQY_L[i] = (DetMessage*)ftSQY_L_clar->At(i);
	}

	DetMessage **SQ300 = new DetMessage*[fSQ300_clar->GetEntries()];
	for(Int_t i=0;i<fSQ300_clar->GetEntries();i++){
		SQ300[i] = (DetMessage*)fSQ300_clar->At(i);
		// cout << "SQ20 amp " << SQ300[i]->GetValue() << endl;
	}

	DetMessage **tSQ300 = new DetMessage*[ftSQ300_clar->GetEntries()];
	for(Int_t i=0;i<ftSQ300_clar->GetEntries();i++){
		tSQ300[i] = (DetMessage*)ftSQ300_clar->At(i);
	}


	// Add processing methods after this line

}

ClassImp(TestAnalysis)
