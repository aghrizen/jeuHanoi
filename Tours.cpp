/*
 * Déclaration d'un constructeur par défaut
 */
Tour::Tour()
: m_top(-1)
{}

/**
  Constructeur normal: une tour peut contenir au plus n disques
  @param[in] n - nombre de tours
  @param[in] vide - si vrai alors 0
*/
Tour::Tour(int n, bool vide)
: m_top(-1)
{
  assign(n, vide);
}

/**
  Accesseur au disque k
  @param[in] k - numero du disque
  @return disque k
*/
Disque Tour::getDisque(int k) const
{
  return m_pilier[k];
}

/**
  Accesseur a l'indice du sommet
  @return indice du sommet
*/
int Tour::sommet() const
{
  return m_top;
}

/**
  Met un disque au sommet du pilier
  @param[in] d - un Disque
*/
void Tour::push(const Disque& d)
{
  m_pilier[++m_top] = d;
}

/**
  Depile le disque au sommet
*/
void Tour::pop()
{
  m_pilier[m_top--] = Disque(m_dim,0);
}

/**
  Retaille la tour et empile les disques
  @param[in] taille - taille des disques
  @param[in] vide - si vrai alors 0
*/
void Tour::assign(int taille, bool vide)
{
  m_dim = taille;
  // Empile les disques par ordre de diamÃ¨tre decroissant
  for (int ix = 0, t = taille; ix < taille; ++ix, --t)
  {
    m_pilier[ix] = Disque(taille, vide ? 0 : t);
  }
  // Actualise le sommet
  m_top = (!vide) ?  taille-1 : -1;
}

