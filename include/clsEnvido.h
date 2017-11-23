#ifndef CLSENVIDO_H
#define CLSENVIDO_H


class clsEnvido
{
    public:
        clsEnvido();
        ~clsEnvido();

        int get_envido(){return envido;};
        int get_envido_envido(){return envido_envido;};
        int get_real_envido(){return real_envido;};
        int get_falta_envido(){return falta_envido;};

        void set_envido();
        void set_envido_envido();
        void set_real_envido();
        void set_falta_envido();


    private:
        int envido;
        int envido_envido;
        int real_envido;
        int falta_envido;

};

#endif // CLSENVIDO_H
