import tkinter as tk
from tkinter import ttk
from random import randint
from pynput import mouse
from PIL import Image, ImageGrab


def get_mouse_position(func):
    def wrapper(*args):
        print(f'Wrapper Args: {args}')
        with mouse.Listener(on_click=func) as ml:
            ml.join()

    return wrapper


class MainWindow:
    def __init__(self, root):
        #  Setting up the Window
        self.root = root
        self.width = 570
        self.height = 370
        self.root.title('Color Palette')
        self.root.geometry(f'{self.width}x{self.height}')
        self.default_color = (255, 255, 255)  # Default color To display when program opens
        self.current_color = '#FFFFFF'
        self.current_selection = None
        #  Setting-up top most container to store other TOP containers
        self.top_container = tk.Frame(self.root)
        self.top_container.pack(side=tk.TOP, pady=20)
        #  Top Left container to store the Canvas Panel
        self.canvas_frame = tk.Frame(self.top_container)
        self.canvas_frame.grid(row=0, column=0)
        #  Setting-up the Canvas Panel
        #  #{:02x} - produces a 2 digit hex value with a preceding 0
        self.color_panel = tk.Canvas(self.canvas_frame, width=100, height=100,
                                     bg='#{:02x}{:02x}{:02x}'
                                     .format(self.default_color[0], self.default_color[1], self.default_color[2]))
        self.color_panel.pack(padx=10, pady=10)

        self.label_frame = tk.Frame(self.top_container)
        self.label_frame.grid(row=0, column=1)

        self.color_label_rgb = tk.Label(self.label_frame, text=f'RGB:\t{self.default_color}')
        self.color_label_rgb.pack(side=tk.TOP, anchor=tk.W, padx=10)
        self.color_label_hex = tk.Label(self.label_frame,
                                        text='Hex:\t#{:02X}{:02X}{:02X}'
                                        .format(self.default_color[0], self.default_color[1], self.default_color[2]))
        self.color_label_hex.pack(side=tk.TOP, anchor=tk.W, padx=10)

        self.button_frame = tk.Frame(self.top_container)
        self.button_frame.grid(row=1, column=0, columnspan=2)

        self.new_button = tk.Button(self.button_frame, text='New Color')
        self.new_button.bind('<Button-1>', self.set_color_from_screen)
        self.new_button.grid(row=1, column=0, padx=(0, 5), pady=5)

        save_button = tk.Button(self.button_frame, text='Save Color')
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

    def set_color_from_screen(self, event):
        location = get_px_loc()
        x = location[0]
        y = location[1]
        selection_box = (x, y, x + 1, y + 1)
        image_grab = ImageGrab.grab(bbox=selection_box)
        image_rgb = image_grab.convert('RGB')
        r, g, b = image_rgb.getpixel((0, 0))
        self.change_color((r, g, b))


@get_mouse_position
def get_px_loc(x, y, button, clicked):
    if clicked and button == mouse.Button.left:
        return x, y


if __name__ == "__main__":
    window = tk.Tk()
    gui = MainWindow(window)
    window.mainloop()
