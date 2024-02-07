import tkinter as tk
from tkinter import ttk
from random import randint
from pynput import mouse
from pynput import keyboard
from PIL import Image, ImageGrab


class MainWindow:
    def __init__(self, root):
        self.root = root
        self.width = 550
        self.height = 370
        self.root.title('Color Palette')
        self.root.geometry(f'{self.width}x{self.height}')
        self.default_color = (255, 255, 255)
        self.current_color = '#FFFFFF'
        self.current_selection = None

        self.top_container = tk.Frame(self.root)
        self.top_container.pack(side=tk.TOP, pady=20)

        self.left_top = tk.Frame(self.top_container)
        self.left_top.grid(row=0, column=0)

        self.color_panel = tk.Canvas(self.left_top, width=100, height=100,
                                     bg='#{:02x}{:02x}{:02x}'
                                     .format(self.default_color[0], self.default_color[1], self.default_color[2]))
        self.color_panel.pack(padx=10, pady=10)

        self.right_top = tk.Frame(self.top_container)
        self.right_top.grid(row=0, column=1)

        self.color_label_rgb = tk.Label(self.right_top, text=f'RGB:\t{self.default_color}')
        self.color_label_rgb.pack(side=tk.TOP, anchor=tk.W, padx=10)
        self.color_label_hex = tk.Label(self.right_top,
                                        text='Hex:\t#{:02X}{:02X}{:02X}'
                                        .format(self.default_color[0], self.default_color[1], self.default_color[2]))
        self.color_label_hex.pack(side=tk.TOP, anchor=tk.W, padx=10)

        self.button_container = tk.Frame(self.top_container)
        self.button_container.grid(row=1, column=0, columnspan=2)
        new_button = tk.Button(self.button_container, text='New Color')
        new_button.grid(row=1, column=0, padx=(0, 5), pady=5)
        save_button = tk.Button(self.button_container, text='Save Color')
        save_button.bind('<Button-1>', self.change_palette)
        save_button.grid(row=1, column=1, padx=(0, 5), pady=5)

        separator = ttk.Separator(self.root)
        separator.pack(fill='x', pady=10)

        self.bottom_container = tk.Frame(self.root)
        self.bottom_container.pack(pady=10)

        self.create_palette_array()

    def change_color(self, color):
        hex_color = "#{:02X}{:02X}{:02X}".format(color[0], color[1], color[2])
        self.color_panel.config(bg=hex_color)
        self.color_label_rgb.config(text=f'RGB:\t{color}')
        self.color_label_hex.config(text=f'Hex:\t{hex_color}')
        self.current_color = hex_color

    def create_palette_array(self, load=False):
        if load is False:
            color_array = []
            i = 0
            while i < 45:
                color_array.append((randint(0, 255), randint(0, 255), randint(0, 255)))
                i += 1
        else:
            color_array = load

        row = 0
        col = 0
        # palette = [[None for _ in range(15)] for _ in range(3)]
        for color in color_array:
            palette_panel = tk.Canvas(self.bottom_container, width=25, height=25,
                                      bg="#{:02x}{:02x}{:02x}".format(color[0], color[1], color[2]),
                                      relief='solid', borderwidth=2)
            palette_panel.bind("<Button-1>", lambda event, c=color: self.change_color(c))
            palette_panel.grid(row=row, column=col, padx=2, pady=2)
            palette_panel.bind("<Button-3>", lambda event, s=palette_panel: self.select_palette(s))
            # palette[row][col] = palette_panel
            col += 1
            if col == 15:
                row += 1
                col = 0
        # print(palette)

    def change_palette(self, event):
        # TODO: Change the palette color
        self.current_selection.config(bg=self.current_color)

    def select_palette(self, canvas_object):
        # TODO: Put current canvas object in a variable and show whats selected.
        if self.current_selection is None:
            self.current_selection = canvas_object
            self.current_selection.config(relief='raised')  # Select the new palette
            # print(self.current_selection)
        elif self.current_selection is not canvas_object:
            # print(self.current_selection)
            self.current_selection.config(relief='solid')  # Deselect the old palette
            canvas_object.config(relief='raised')  # Select the new palette
            self.current_selection = canvas_object
            # print(self.current_selection)
        else:
            print(f'{canvas_object} already selected.')


if __name__ == "__main__":
    window = tk.Tk()
    gui = MainWindow(window)
    window.mainloop()
