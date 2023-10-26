from os import environ
environ['PYGAME_HIDE_SUPPORT_PROMPT'] = '1'

import pygame
import numpy as np


def display(caption, image, resolution):
    pygame.init()

    # screen = pygame.display.set_mode(resolution, pygame.FULLSCREEN)
    screen = pygame.display.set_mode(resolution)

    pygame.display.set_caption(caption)
    image_surface = pygame.surfarray.make_surface(np.array(image, dtype=np.uint8))

    screen.blit(image_surface, (0, 0))
    pygame.display.flip()

    running = True
    while running:
        for event in pygame.event.get():
            if event.type == pygame.QUIT or event.type == pygame.KEYDOWN:
                running = False

    pygame.quit()
