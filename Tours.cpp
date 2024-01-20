#include "Tours.hpp"
#include "Disque.hpp"
//Tour vide
Tour::Tour(int TowerTag)
{
  TourTag = TowerTag;
}

//Tour rempli de 1 à n
Tour::Tour(int TowerTag, int n)
{
  TourTag = TowerTag;
  for (int indexDisque = n; indexDisque > 0; indexDisque--)
  {
    Disque tempDisque = Disque(n, MAX_SIZE_GAME);
    ListeDisqueInOrder.push_back(tempDisque);
  }
}

/**
  Accesseur au disque k
  @param[in] k - numero du disque
  @return disque k
*/
Disque Tour::getDisque(int k)
{
  if(ListeDisqueInOrder.size > k)
  {
    return ListeDisqueInOrder(k);
  }
  else
  {
    return NULL;
  }
}

/**
  Accesseur a l'indice du sommet
  @return indice du sommet
*/
bool Tour::MoveDisk(Tour *TourDestination);
{
  Disque* myTopDisk =   ListeDisqueInOrder.back();
  bool DidItSuccess;
  DidItSuccess = TourDestination->AddDisk(myTopDisk)
  //Si on a réussi à déplacer le disque
  if (DidItSuccess == true)
  {
    //Supprime le disque de la tour actuelle
    ListeDisqueInOrder.popback()
  }
  return DidItSuccess;
}

/**
  Met un disque au sommet du pilier
  @param[in] d - un Disque
*/
bool Tour::AddDisk(Disque *newDisque)
{
  //Obtient le dernier element 
  Disque TopDisque = ListeDisqueInOrder.back();

  //Regarde si on a le droit d'ajouter le disque
  if (TopDisque.getTaille < newDisque->getTaille())
  {
    ListeDisqueInOrder.push_back(&newDisque);
    return true;
  }
  else
  {
    return false;
  }
}

