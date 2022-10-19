#ifndef __CONTROLADORA_H__
#define __CONTROLADORA_H__
#include "Escenario.h"

class CControladora {
    public:
        CControladora(){
            oEscenario = new CEscenario;
        };
        ~CControladora(){};

    private:
        CEscenario *oEscenario;


};

#endif
