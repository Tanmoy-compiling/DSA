from pdf2image import convert_from_path
import pytesseract

# Convert PDF to images
pages = convert_from_path('path_to_your_pdf_file.pdf')

# Extract text from each image using OCR
ocr_text = ''
for page in pages:
    ocr_text += pytesseract.image_to_string(page)

# Save or print the extracted text
with open('output.txt', 'w') as f:
    f.write(ocr_text)
