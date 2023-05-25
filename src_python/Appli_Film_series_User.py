import random

class Media:
    def __init__(self, titre, description, notation, acteur_principal, plateforme, style):
        self.titre = titre
        self.description = description
        self.notation = notation
        self.acteur_principal = acteur_principal
        self.plateforme = plateforme
        self.style = style

class Categorie:
    def __init__(self, nom):
        self.nom = nom
        self.medias = []
        self.nbMedia = 0

    def ajouter_media(self, media):
        if self.nbMedia < 10:
            self.medias.append(media)
            self.nbMedia += 1
            print("Le média a été ajouté avec succès.\n")
        else:
            print("La liste des médias est pleine. Impossible d'ajouter un nouveau média.\n")

    def afficher_medias(self):
        print(f"----- Liste des médias dans la catégorie {self.nom} -----")
        if self.nbMedia == 0:
            print("Aucun média n'a été ajouté.\n")
            return

        for i, media in enumerate(self.medias):
            print(f"Média {i+1}:")
            print(f"Titre: {media.titre}")
            print(f"Description: {media.description}")
            print(f"Notation: {media.notation} étoiles")
            print(f"Acteur principal: {media.acteur_principal}")
            print(f"Plateforme: {media.plateforme}")
            print(f"Style: {media.style}")
            print()

    def rechercher_medias(self, critere, style=None):
        print(f"----- Résultats de recherche dans la catégorie {self.nom} -----")
        if self.nbMedia == 0:
            print("Aucun média n'a été ajouté.\n")
            return

        results = []
        for media in self.medias:
            if critere.lower() in media.titre.lower() or critere.lower() in media.acteur_principal.lower() or critere.lower() in media.plateforme.lower():
                if style is None or style.lower() in media.style.lower():
                    results.append(media)

        if len(results) == 0:
            print("Aucun média correspondant n'a été trouvé.\n")
            return

        for i, media in enumerate(results):
            print(f"Média {i+1}:")
            print(f"Titre: {media.titre}")
            print(f"Description: {media.description}")
            print(f"Notation: {media.notation} étoiles")
            print(f"Acteur principal: {media.acteur_principal}")
            print(f"Plateforme: {media.plateforme}")
            print(f"Style: {media.style}")
            print()

def generer_medias():
    films = [
        {
            "titre": "Inception",
            "description": "Un voleur spécialisé dans l'extraction d'informations en infiltrant les rêves des autres est chargé de réaliser l'inverse : implanter une idée dans l'esprit d'un individu.",
            "acteur_principal": "Leonardo DiCaprio",
            "plateforme": "Netflix",
            "style": "Science-fiction, Thriller"
        },
        {
            "titre": "Game Night",
            "description": "Un groupe d'amis organise une soirée jeu où un meurtre mystérieux est simulé, mais les choses prennent une tournure inattendue lorsque des vrais criminels s'en mêlent.",
            "acteur_principal": "Jason Bateman",
            "plateforme": "Amazon Prime",
            "style": "Comédie, Mystère"
        },
        # Ajoutez plus de films ici
    ]

    series = [
        {
            "titre": "Stranger Things",
            "description": "Un groupe d'enfants se lance à la recherche d'un de leurs amis disparu et découvre un univers parallèle peuplé de créatures terrifiantes.",
            "acteur_principal": "Millie Bobby Brown",
            "plateforme": "Netflix",
            "style": "Drame, Fantastique"
        },
        {
            "titre": "Breaking Bad",
            "description": "Un professeur de chimie atteint d'un cancer se lance dans la production de méthamphétamine pour assurer l'avenir financier de sa famille.",
            "acteur_principal": "Bryan Cranston",
            "plateforme": "Netflix",
            "style": "Drame, Crime"
        },
        # Ajoutez plus de séries ici
    ]

    animes = [
        {
            "titre": "Death Note",
            "description": "Un étudiant trouve un carnet surnaturel qui lui permet de tuer toute personne dont il connaît le nom.",
            "acteur_principal": "Mamoru Miyano",
            "plateforme": "Crunchyroll",
            "style": "Thriller, Mystère"
        },
        {
            "titre": "One Piece",
            "description": "Un jeune pirate en quête du trésor ultime parcourt les mers aux côtés de son équipage tout en affrontant de redoutables ennemis.",
            "acteur_principal": "Mayumi Tanaka",
            "plateforme": "Funimation",
            "style": "Action, Aventure"
        },
        # Ajoutez plus d'animés ici
    ]

    films_categorie = Categorie("Films")
    series_categorie = Categorie("Series")
    animes_categorie = Categorie("Animes")

    for film in films:
        media = Media(film["titre"], film["description"], random.uniform(1, 5), film["acteur_principal"], film["plateforme"], film["style"])
        films_categorie.ajouter_media(media)

    for serie in series:
        media = Media(serie["titre"], serie["description"], random.uniform(1, 5), serie["acteur_principal"], serie["plateforme"], serie["style"])
        series_categorie.ajouter_media(media)

    for anime in animes:
        media = Media(anime["titre"], anime["description"], random.uniform(1, 5), anime["acteur_principal"], anime["plateforme"], anime["style"])
        animes_categorie.ajouter_media(media)

    return [films_categorie, series_categorie, animes_categorie]

def classement(categories):
    print("----- Classement des médias -----")
    medias = []

    for categorie in categories:
        medias.extend(categorie.medias)

    medias.sort(key=lambda media: media.notation, reverse=True)

    for i, media in enumerate(medias):
        print(f"Média {i+1}:")
        print(f"Titre: {media.titre}")
        print(f"Description: {media.description}")
        print(f"Notation: {media.notation} étoiles")
        print(f"Acteur principal: {media.acteur_principal}")
        print(f"Plateforme: {media.plateforme}")
        print(f"Style: {media.style}")
        print()


def main():
    categories = generer_medias()

    while True:
        print("----- Menu -----")
        print("1. Afficher la liste des médias par catégorie")
        print("2. Rechercher un média")
        print("3. Classement")
        print("4. Quitter")
        choix = input("Votre choix : ")

        if choix == "1":
            print("Catégories disponibles : Films, Series, Animes")
            categorie = input("Choisissez une catégorie : ")
            for c in categories:
                if c.nom.lower() == categorie.lower():
                    c.afficher_medias()
                    break
            else:
                print("Catégorie invalide. Veuillez sélectionner une catégorie valide.\n")

        elif choix == "2":
            critere = input("Entrez votre critère de recherche (acteur, titre ou plateforme) : ")
            style = input("Entrez le style du média (facultatif) : ")

            print("Catégories disponibles : Films, Series, Animes")
            categorie = input("Choisissez une catégorie : ")

            for c in categories:
                if c.nom.lower() == categorie.lower():
                    c.rechercher_medias(critere, style)
                    break
            else:
                print("Catégorie invalide. Veuillez sélectionner une catégorie valide.\n")


        elif choix == "3":
            classement(categories)


        elif choix == "4":
            print("Arrêt de l'application.")
            break

        else:
            print("Choix invalide. Veuillez sélectionner une option valide.\n")

if __name__ == "__main__":
    main()
