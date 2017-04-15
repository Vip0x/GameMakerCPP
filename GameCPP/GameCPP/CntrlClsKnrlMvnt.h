class ClsCmntrmvnmt :public ClsObjtBtmp {
private:
	bool cntrlkys[4] = { false,false,false,false };
	void FcntnMvmntPrnj(void);
protected:
	bool GmesxtScp = false;
	void FnctnClntrlrPrsj();
	ALLEGRO_EVENT_QUEUE *VrblEvntQueue = NULL;
	void FcntnCrtEvnt();
};
void ClsCmntrmvnmt::FnctnClntrlrPrsj() {
	ALLEGRO_EVENT EvntMvnt;
	al_wait_for_event(VrblEvntQueue, &EvntMvnt);
	if (EvntMvnt.type == ALLEGRO_EVENT_DISPLAY_CLOSE) { exit(-1); }
	else if (EvntMvnt.type == ALLEGRO_EVENT_TIMER) {
		this->FcntnMvmntPrnj();
	}
	else if (EvntMvnt.type == ALLEGRO_EVENT_KEY_DOWN) {
		switch (EvntMvnt.keyboard.keycode) {
		case ALLEGRO_KEY_UP: cntrlkys[KyUpCnst] = true; break;
		case ALLEGRO_KEY_DOWN: cntrlkys[KyDnwCnst] = true; break;
		case ALLEGRO_KEY_LEFT: cntrlkys[KyLftCnst] = true; break;
		case ALLEGRO_KEY_RIGHT: cntrlkys[KyRgtCnst] = true; break;
		default: std::cout << "Tecla Invalida" << std::endl; break;
		}
	}
	else if (EvntMvnt.type == ALLEGRO_EVENT_KEY_UP) {
		switch (EvntMvnt.keyboard.keycode) {
		case ALLEGRO_KEY_ESCAPE: {GmesxtScp = true; break; }
		case ALLEGRO_KEY_UP: cntrlkys[KyUpCnst] = false; this->CntrlWtdhMvnt = 1; break;
		case ALLEGRO_KEY_DOWN: cntrlkys[KyDnwCnst] = false; this->CntrlWtdhMvnt = 1; break;
		case ALLEGRO_KEY_LEFT: cntrlkys[KyLftCnst] = false; this->CntrlWtdhMvnt = 1; break;
		case ALLEGRO_KEY_RIGHT: cntrlkys[KyRgtCnst] = false; this->CntrlWtdhMvnt = 1; break;
		default: std::cout << "ERROR! Invalido" << std::endl; break;
		}
	}
}
void ClsCmntrmvnmt::FcntnCrtEvnt() {
	VrblEvntQueue = al_create_event_queue();
}
void ClsCmntrmvnmt::FcntnMvmntPrnj(void) {
	if (cntrlkys[KyUpCnst]) { this->BffrPrsjMvnt_y -= 3; this->CntrlHgthMvnt = KyRgtCnst; }
	if (cntrlkys[KyDnwCnst]) { this->BffrPrsjMvnt_y += 3; this->CntrlHgthMvnt = KyUpCnst; }
	if (cntrlkys[KyLftCnst]) { this->BffrPrsjMvnt_x -= 3; this->CntrlHgthMvnt = KyDnwCnst; }
	if (cntrlkys[KyRgtCnst]) { this->BffrPrsjMvnt_x += 3; this->CntrlHgthMvnt = KyLftCnst; }
	this->VrblRcrgrlnz = true;
}
