class ClsFdndLnzFrstGms : ClsCmntrmvnmt {
protected:
	ALLEGRO_DISPLAY *VrblCmpLnzGm;
	ALLEGRO_TIMER *VrblCdrsSgds;
	void FcntnCntrlIntvnt();
public:
	void Fcntngmlpp();
};
void ClsFdndLnzFrstGms::Fcntngmlpp() {
	al_init();
	al_install_keyboard();
	if (!al_is_keyboard_installed()) { std::cout << "Error al Instalar" << std::endl; }
	else { std::cout << "Instalado Correctamente!" << std::endl; }
	VrblCmpLnzGm = al_create_display(CnstWtdh, CnstHgth);
	VrblCdrsSgds = al_create_timer(1.0 / 20);
	this->FcntnCrtdObjtPrsj(); this->Fnctncnmntrbckbffr(VrblCmpLnzGm);
	this->FcntnCrtEvnt(); this->FcntnCntrlIntvnt();
	al_flip_display();
	al_start_timer(VrblCdrsSgds);
	while (!this->GmesxtScp) {
		this->FnctnClntrlrPrsj();
		if (this->VrblRcrgrlnz) {
			this->FcntnCgrBtmpBffr();
			if (this->PsrnjAnmcn_x != this->BffrPrsjMvnt_x || this->PsrnjAnmcn_y != this->BffrPrsjMvnt_y) {
				this->PsrnjAnmcn_x = this->BffrPrsjMvnt_x;	this->PsrnjAnmcn_y = this->BffrPrsjMvnt_y;
				this->CntrlWtdhMvnt++;
				if (this->CntrlWtdhMvnt > 2) this->CntrlWtdhMvnt = 0;
			}
		}
		al_flip_display();
	}
	al_destroy_bitmap(this->PrsnjPrncplI);
	al_destroy_bitmap(this->VrblMpUn);
	al_destroy_display(VrblCmpLnzGm);
}
void ClsFdndLnzFrstGms::FcntnCntrlIntvnt() {
	al_register_event_source(this->VrblEvntQueue, al_get_display_event_source(VrblCmpLnzGm));
	al_register_event_source(this->VrblEvntQueue, al_get_timer_event_source(VrblCdrsSgds));
	al_register_event_source(this->VrblEvntQueue, al_get_keyboard_event_source());
}

