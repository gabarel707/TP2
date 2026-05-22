#ifndef NO_H
#define NO_H

class No {
private:
    int id;
    char tipo;

public:
    No();
    No(int id, char tipo);

    int getId() const;
    char getTipo() const;
};

#endif
