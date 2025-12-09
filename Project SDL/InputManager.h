#pragma once                          // Empêche que ce header soit inclus plusieurs fois dans le projet

#include "SDL.h"                      // Inclut la bibliothèque SDL (événements, clavier, etc.)
#include <iostream>                   // (Actuellement pas utilisé, mais permet d'afficher dans la console)
#include <map>                        // (Actuellement pas utilisé, prévu peut-être pour un futur usage)


class InputManager
{
private:

	// Structure qui représente l'état d'une touche du clavier
	struct State
	{
		bool isDown;                  // true uniquement la frame où la touche vient d'être pressée
		bool isHeld;                  // true tant que la touche est maintenue enfoncée
		bool isUp;                    // true uniquement la frame où la touche vient d'être relâchée
	};

	// Tableau qui contient l'état de TOUTES les touches (indexées par SDL_Scancode)
	State m_states[SDL_NUM_SCANCODES];

	//BONUS
	//const Uint8* m_keyboardState;    // Pointeur vers l'état du clavier fourni par SDL (approche alternative)
	//Uint8 m_previousKeyboardState[SDL_NUM_SCANCODES] = { 0 }; // Copie de l'état du clavier à la frame précédente

	// Constructeur de InputManager
	InputManager()
	{
		//BONUS
		//m_keyboardState = SDL_GetKeyboardState(NULL); // Récupère l'état clavier version SDL (si on utilise l'approche BONUS)
		std::memset(m_states, 0, sizeof(State) * SDL_NUM_SCANCODES);
	}

public:
	// Méthode statique qui renvoie l'instance unique de InputManager (pattern Singleton)
	static InputManager* Get();

	// Fonction appelée à CHAQUE frame pour mettre à jour les états des touches
	void Update();

	/*
	// Ancienne version des fonctions, qui utilisait directement les tableaux SDL :
	bool IsDown(SDL_Scancode key)
	{
		// Était relâchée à la frame précédente et est pressée maintenant
		return m_previousKeyboardState[key] == 0 && m_keyboardState[key] == 1;
	}

	bool IsHeld(SDL_Scancode key)
	{
		// Est simplement pressée dans l'état actuel
		return m_keyboardState[key];
	}

	bool IsUp(SDL_Scancode key)
	{
		// Était pressée à la frame précédente et relâchée maintenant
		return m_previousKeyboardState[key] == 1 && m_keyboardState[key] == 0;
	}
	*/

	// Vérifie si une touche vient d'être pressée à cette frame (événement "down")
	bool IsDown(SDL_KeyCode key);

	// Vérifie si une touche est maintenue enfoncée (état "held")
	bool IsHeld(SDL_KeyCode key);

	// Vérifie si une touche vient d'être relâchée à cette frame (événement "up")
	bool IsUp(SDL_KeyCode key);
};
