#include "InputManager.h"

// Méthode statique qui renvoie l'instance unique de InputManager (pattern Singleton)
InputManager* InputManager::Get()
{
	static InputManager instance; // Objet statique : créé une seule fois, réutilisé à chaque appel
	return &instance;             // On renvoie l'adresse de cette unique instance
}

// Fonction appelée à CHAQUE frame pour mettre à jour les états des touches
void InputManager::Update()
{
	// 1) Met à jour les états "transitoires" (isDown / isUp) et gère isHeld
	for (int i = 0; i < SDL_NUM_SCANCODES; ++i)
	{
		State& state = m_states[i]; // Raccourci vers l'état de la touche i

		if (state.isDown)          // Si la touche venait d'être pressée à la frame précédente
			state.isHeld = true;   // On considère maintenant qu'elle est maintenue (held)

		if (state.isUp)            // Si la touche venait d'être relâchée à la frame précédente
			state.isHeld = false;  // Elle n'est plus maintenue

		state.isDown = false;      // On réinitialise isDown pour cette nouvelle frame
		state.isUp = false;        // On réinitialise isUp pour cette nouvelle frame
	}

	// 2) Récupère tous les événements en attente (clavier, souris, etc.)
	SDL_Event event;
	while (SDL_PollEvent(&event))  // Tant qu'il y a des événements dans la file
	{
		switch (event.type)        // On regarde le type de l'événement
		{
		case SDL_KEYDOWN:          // Une touche vient d'être enfoncée
		{
			if (event.key.repeat)  // Si c'est un répétition automatique (touche maintenue)
				break;             // On ignore cet événement pour ne pas compter plusieurs "down"

			// On récupère le scancode de la touche et on marque isDown pour cette frame
			m_states[event.key.keysym.scancode].isDown = true;
			break;
		}
		case SDL_KEYUP:            // Une touche vient d'être relâchée
		{
			// On récupère le scancode de la touche et on marque isUp pour cette frame
			m_states[event.key.keysym.scancode].isUp = true;
			break;
		}
		}
	}

	// Approche alternative (BONUS) avec les tableaux d'état clavier de SDL :
	//std::memcpy(m_previousKeyboardState, m_keyboardState, SDL_NUM_SCANCODES * sizeof(Uint8));
	//SDL_PumpEvents();            // Met à jour l'état du clavier côté SDL
}

bool InputManager::IsDown(SDL_KeyCode key)
{
	// Convertit un SDL_KeyCode (ex : SDLK_SPACE) en SDL_Scancode (position physique)
	SDL_Scancode scancode = SDL_GetScancodeFromKey(key);

	// Renvoie le booléen isDown associé à cette touche
	return m_states[scancode].isDown;
}

// Vérifie si une touche est maintenue enfoncée (état "held")
bool InputManager::IsHeld(SDL_KeyCode key)
{
	SDL_Scancode scancode = SDL_GetScancodeFromKey(key);

	return m_states[scancode].isHeld;
}

// Vérifie si une touche vient d'être relâchée à cette frame (événement "up")
bool InputManager::IsUp(SDL_KeyCode key)
{
	SDL_Scancode scancode = SDL_GetScancodeFromKey(key);

	return m_states[scancode].isUp;
}