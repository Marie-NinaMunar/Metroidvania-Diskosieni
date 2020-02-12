#include <stdio.h>
#if defined(_WIN32)
    #define PAUSE system("PAUSE");
    #define CLEAR system("CLS");
#elif defined(__unix)
    #define PAUSE system("read -rsp $'Press any key to continue...\n' -n 1"); //Peut ne pas fonctionner parfois (PC de l'université par exemple)
    #define CLEAR system("clear");
#else
    #define PAUSE
    #define CLEAR
#endif

typedef struct {
    int x,y;
} position_t;

typedef enum {
    FALSE,
    TRUE
} boolean_t;

/**
 * 
*/
typedef enum {
    SU, /**< Sprite de non déplacement (Stand-Up) */
    DEP1, /**< Sprite de déplacement n°1 */
    DEP2, /**< Sprite de déplacement n°2 */
    DEP3, /**< Sprite de déplacement n°3 */
    DEP4, /**< Sprite de déplacement n°4 */
    DEP5, /**< Sprite de déplacement n°5 */
    DEP6, /**< Sprite de déplacement n°6 */
    DEP7, /**< Sprite de déplacement n°7 */
    DEP8, /**< Sprite de déplacement n°8 */
    JP1, /**< Sprite de saut (Jump) n°1 */
    JP2, /**< Sprite de saut (Jump) n°2 */
    JP3, /**< Sprite de saut (Jump) n°3 */
    JP4, /**< Sprite de saut (Jump) n°4 */
    JP5, /**< Sprite de saut (Jump) n°5 */
    JP6, /**< Sprite de saut (Jump) n°6 */
    JP7, /**< Sprite de saut (Jump) n°7 */
    JP8 /**< Sprite de saut (Jump) n°8 */
} indSpritePer;

/**
 * 
*/
typedef struct salle_s{
    char * nomFichier; /**< Nom du fichier qui a généré la salle (utile pour les sauvegardes) */

    int hauteur; /**< Hauteur de la salle en blocks */
    int largeur; /**< Longueur de la salle en blocks */
    int ** mat; /**< Matrice de positionnement des objets */

    int spriteActuel; /**< Indice du sprite à afficher */

    //liste des portes
} salle_t;

typedef struct fraction_s{
    int numerateur;
    int denominateur;
}fraction_t;

typedef struct fracPos_s{
    fraction_t delta_x; /**< Différence de position sur l'axe x à ajouter à la position entière (valeur comprise -1 et 1) */
    fraction_t delta_y; /**< Différence de position sur l'axe y à ajouter à la position entière (valeur comprise -1 et 1) */
} fracPos_t;

typedef struct personnage_s{
    int pv;
    int vit_dep;
    int vit_att;
    position_t pos;
    fracPos_t delta; /**< Différence de position à ajouter à la position entière */
    int spriteActuel; /**< Indice du sprite à afficher */

    char forme; /**< Forme du personnage H = humain, F = renard */
    //hitbox en dur possible

} personnage_t;

typedef struct type_monstre_s{
    int pv_base;
    int vit_dep;
    int vit_att;

    char* sprites; /**< Chemin d'accès aux sprites qui seront utilisés*/

    int largeur;
    int haunteur;

    boolean_t passeEntites;
    boolean_t passeBlocs;

    //comportement (pointeur sur fonction)
} type_monstre_t;

typedef struct monstre_s{
    type_monstre_t * type;
    int pv;
    int spritesActuel; /**< Indice du sprite à afficher */
    position_t pos;
    fracPos_t delta; /**< Différence de position à ajouter à la position entière */

} monstre_t;

typedef struct bloc_s{

    int id_sprite;
    position_t pos;

} bloc_t;

typedef struct porte_s{
    position_t pos;
    char* salleSuivante;
    position_t pos_arrivee;
    char* listeSprites;
    int spritesActuel;
} porte_t;