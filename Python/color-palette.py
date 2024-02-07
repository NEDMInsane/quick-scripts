import tkinter as tk
from tkinter import ttk
from random import randint


class MainWindow:
    def __init__(self, root):
        self.root = root
        self.width = 500
        self.height = 350
        root.title('Color Palette')
        root.geometry(f'{self.width}x{self.height}')
        self.default_color = (255, 255, 255)

        self.top_container = tk.Frame(self.root)
        self.top_container.pack(side=tk.TOP)
        self.top_container.columnconfigure = 4
        self.top_container.rowconfigure = 3

        self.left_top = tk.Frame(self.top_container)
        self.left_top.pack()

        self.color_panel = tk.Canvas(self.left_top, width=100, height=100,
                                     bg="#{:02x}{:02x}{:02x}"
                                     .format(self.default_color[0], self.default_color[1], self.default_color[2]))
        self.color_panel.pack(padx=10, pady=10)

        self.color_label_rgb = tk.Label(self.top_container, text=self.default_color)
        self.color_label_rgb.pack()
        self.color_label_hex = tk.Label(self.top_container,
                                        text="#{:02X}{:02X}{:02X}"
                                        .format(self.default_color[0], self.default_color[1], self.default_color[2]))
        self.color_label_hex.pack()

        new_button = tk.Button(self.top_container, text='New Color')
        new_button.pack(side=tk.RIGHT, padx=5)
        save_button = tk.Button(self.top_container, text='Save Color')
        save_button.pack(side=tk.RIGHT, padx=5)

        separator = ttk.Separator(self.root)
        separator.pack(fill='x', pady=5)

        self.bottom_container = tk.Frame(self.root)
        self.bottom_container.pack()

        self.create_palette_array()

    def change_color_panel(self, color):
        hex_color = "#{:02X}{:02X}{:02X}".format(color[0], color[1], color[2])
        self.color_panel.config(bg=hex_color)
        self.change_color_labels(color, hex_color)

    def change_color_labels(self, color, hex_color):
        self.color_label_rgb.config(text=color)
        self.color_label_hex.config(text=hex_color)

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
        for color in color_array:
            palette_panel = tk.Canvas(self.bottom_container, width=25, height=25,
                                      bg="#{:02x}{:02x}{:02x}".format(color[0], color[1], color[2]))
            palette_panel.bind("<Button-1>", lambda event, c=color: self.change_color_panel(c))
            palette_panel.grid(row=row, column=col, padx=2, pady=2)
            col += 1
            if col == 15:
                row += 1
                col = 0


if __name__ == "__main__":
    window = tk.Tk()
    gui = MainWindow(window)
    window.mainloop()
